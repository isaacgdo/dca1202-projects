#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    /**
     * @brief putData é um função que cria um temporalizador usado na função timerEvent para possibilitar o envio constante de dados ao servidor.
     */
    void putData();
    /**
     * @brief stopData é um função que "mata" o temporalizador criado pela função putData , fazendo com que o envio de dados ao servidor cesse.
     */
    void stopData();
    /**
     * @brief getIP é um função que grava o conteudo pressente no campo de texto do objeto lineEdit em uma Qstring.
     */
    QString getIP();
    void tcpConnect();
    void tcpDisconnect();
    void timerEvent(QTimerEvent *event);

private:
    int timerID;
    Ui::MainWindow *ui;
    QTcpSocket *socket;
};


#endif // MAINWINDOW_H
