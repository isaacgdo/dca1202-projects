#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include<plotter.h>
#include <vector>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    tcpConnect();

    connect(ui->pushButtonGet,SIGNAL(clicked(bool)),this,SLOT(getData()));
    connect(ui->pushButtonStop,SIGNAL(clicked(bool)),this,SLOT(stopData()));
    connect(ui->pushButtonConnect,SIGNAL(clicked(bool)),this,SLOT(tcpConnect()));
    connect(ui->pushButtonDisconnect,SIGNAL(clicked(bool)),this,SLOT(tcpDisconnect()));
    connect(ui->pushButtonUpdate,SIGNAL(clicked(bool)),this,SLOT(ListHosts()));
}

QString MainWindow::getIP()
{
    QString ip;
    ip = ui->lineEditIpServer->text();
    qDebug() << ip;
    return ip;
}

void MainWindow::tcpConnect(){
    socket->connectToHost(getIP(),1234);
    if(socket->waitForConnected(3000)){
        qDebug() << "Server: Connected";
        ui->labelStatus->setText("Server: Connected");
    }
    else{
        qDebug() << "Server: Disconnected";
        ui->labelStatus->setText("Server: Disconnected");
    }
}

void MainWindow::tcpDisconnect()
{
    socket->disconnectFromHost();
    qDebug() << "Server: Disconnected";
    ui->labelStatus->setText("Server: Disconnected");
}

void MainWindow::ListHosts()
{
    QMessageBox mensagem;
    QString str,textomensagem;
    ui->listWidget->clear();
    if(socket->state() == QAbstractSocket::ConnectedState){
        socket->write("list\r\n");
        socket->waitForBytesWritten(3000);
        socket->waitForReadyRead(3000);
        if(socket->bytesAvailable() != 0 ){
            while(socket->bytesAvailable()){
                str = socket->readLine().replace("\n","").replace("\r","");
                ui->listWidget->addItem(str);
            }
        }else{
            textomensagem = "ERRO!!! NENHUM HOST FOI ENCONTRADO";
            mensagem.setText(textomensagem);
            mensagem.exec();
        }
    }
    else{
        textomensagem = "ERRO!!! SERVIDOR NÃO CONECTADO";
        mensagem.setText(textomensagem);
        mensagem.exec();
    }

}

void MainWindow::getData(){
    int timing;
    timing = ui->horizontalSlider->value();
    timerID= startTimer(timing*1000);
}
void MainWindow::stopData()
{
    killTimer(timerID);
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    QString str;
    QStringList list;
    qint64 thetime, num;
    double max_x, min_x, min_y, max_y;
    std::vector<double> time;
    std::vector<double> data;
    std::vector<double> tempos_normalizados;
    std::vector<double> dados_normalizados;

    qDebug() << "to get data...";
    if(socket->state() == QAbstractSocket::ConnectedState){
        if(socket->isOpen()){
            qDebug() << "reading...";
            str = "get " + ui->listWidget->currentItem()->text() + " 30\r\n";
            socket->write(str.toStdString().c_str());
            socket->waitForBytesWritten();
            socket->waitForReadyRead();
            qDebug() << socket->bytesAvailable();
            time.clear();
            data.clear();
            while(socket->bytesAvailable()){
                str = socket->readLine().replace("\n","").replace("\r","");
                list = str.split(" ");

                if(list.size() == 2){
                    bool ok;
                    str = list.at(0);
                    thetime = str.toLongLong(&ok);
                    time.push_back(thetime);

                    str = list.at(1);
                    num = str.toLongLong(&ok);
                    data.push_back(num);
                    qDebug() << thetime << ": " << str;
                }
            }
        }
    }

    qDebug()<<data.size()<<time.size();
    //Detreminando os valores máximos e minimos para os tempos e os valores
    max_x = time[0], min_x = time[0];
    min_y = data[0], max_y = data[0];

    //Determinação do valor máximo é minimo para os tempos (algoritmo do trono)
    for(int i = 1 ; i < 30; i++){
        if(time[i] < min_x){
            min_x = time[i];
        }
        else if(time[i] > max_x){
            max_x = time[i];
        }
    }
    //Determinação do valor máximo é minimo para os valores/datas (algoritmo do trono)
    for(int i = 1 ; i < 30; i++){
        if(data[i] < min_y){
            min_y = data[i];
        }
        else if(data[i] > max_y){
            max_y = data[i];
        }
    }

    //normalizando dados
    tempos_normalizados.clear();
    dados_normalizados.clear();
    for(int i = 0; i<30; i++){
        tempos_normalizados.push_back((time[i] - min_x)/(max_x - min_x));
        dados_normalizados.push_back((data[i] - min_y)/(max_y - min_y));
    }
    ui->widget->loadData(tempos_normalizados,dados_normalizados);
}

MainWindow::~MainWindow()
{
    delete socket;
    delete ui;
}
