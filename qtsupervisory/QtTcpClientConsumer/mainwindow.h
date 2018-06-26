#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>

namespace Ui {
class MainWindow;
}

/**
 * @brief A classe MainWindow representa o contâiner da janela da aplicação e seus componentes
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    /**
    * @brief getData é um função que cria um temporalizador usado na função timerEvent para possibilitar o recebimento constante de dados ao servidor.
    */
    void getData();
    /**
    * @brief stopData é um função que "mata" o temporalizador criado pela função getData , fazendo com que o envio de dados ao servidor cesse.
    */
    void stopData();
    /**
    * @brief getIP é um função que grava o conteudo pressente no campo de texto do objeto lineEdit em uma Qstring.
    */
    QString getIP();
    /**
    * @brief ListHosts é um função que lista as máquinas que enviaram dados ao servidos, e mostra os endereços dessas maquinas.
    */
    void ListHosts();
    /**
    * @brief tcpConnect abre uma conexão com um servidor informado
    */
    void tcpConnect();
    /**
    * @brief tcpDisconnect fecha uma conexão com um servidor informado
    */
    void tcpDisconnect();
    /**
    * @brief timerEvent é uma função que vai ser executada a cada vez que o temporizador for acionado e recupera os valores de tempo, e de dados que foram enviados para o servidor por outras máquinas
    */
    void timerEvent(QTimerEvent *event);

private:
    int timerID;
    Ui::MainWindow *ui;
    QTcpSocket *socket;
};

#endif // MAINWINDOW_H
