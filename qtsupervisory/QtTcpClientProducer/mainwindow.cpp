#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include<QTimer>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    socket = new QTcpSocket(this);

    connect(ui->pushButtonPut,SIGNAL(clicked(bool)),this,SLOT(putData()));
    connect(ui->pushButtonStop,SIGNAL(clicked(bool)),this,SLOT(stopData()));
    connect(ui->pushButtonConnect,SIGNAL(clicked(bool)),this,SLOT(tcpConnect()));
    connect(ui->pushButtonDisconnect,SIGNAL(clicked(bool)),this,SLOT(tcpDisconnect()));
}

QString MainWindow::getIP()
{
    QString ip;
    ip = ui->lineEdit->text();
    qDebug() << ip;
    return ip;
}

void MainWindow::tcpConnect(){
    socket->connectToHost(getIP(),1234);
    if(socket->waitForConnected(3000)){
        qDebug() << "Connected";
        ui->labelStatus->setText("Connected");
    }
    else{
        qDebug() << "Disconnected";
        ui->labelStatus->setText("Disconnected");
    }
}

void MainWindow::tcpDisconnect()
{
    socket->disconnectFromHost();
    qDebug() << "Disconnected";
    ui->labelStatus->setText("Disconnected");
}

void MainWindow::putData(){
    int timing;
    timing = ui->horizontalSliderTiming->value();
    timerID= startTimer(timing*1000);
}

void MainWindow::stopData()
{
    killTimer(timerID);
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    int min,max;
    min = ui->horizontalSliderMin->value();
    max = ui->horizontalSliderMax->value();
    QString textomensagem;
    QMessageBox mensagem;
    QDateTime datetime;
    QString str;
    qint64 msecdate;
    if((min > max) || ((min == 0) && (max==0))){
        textomensagem = "ERRO, O VALOR DE MINIMO ESTA MAIOR DO \n QUE O DE MAXIMO, OU AMBOS SAO ZEROS";
        mensagem.setText(textomensagem);
        mensagem.exec();
        killTimer(timerID);
    }else{
        if(socket->state()== QAbstractSocket::ConnectedState){

            msecdate = QDateTime::currentDateTime().toMSecsSinceEpoch();
            str = "set "+ QString::number(msecdate) + " " + QString::number(qrand()%(max - min) + min)+"\r\n";

            qDebug() << str;
            qDebug() << socket->write(str.toStdString().c_str()) << " bytes written";
            if(socket->waitForBytesWritten(3000)){
                qDebug() << "wrote";
            }
            ui->textBrowser->append(str);
        }
    }
}

MainWindow::~MainWindow(){
    delete socket;
    delete ui;
}
