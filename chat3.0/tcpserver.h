#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QDialog>//又可能要添加变量定义和函数声明
#include<QTime>
class QFile;
class QTcpServer;
class QTcpSocket;

namespace Ui {
class TcpServer;
}

class TcpServer : public QDialog
{
    Q_OBJECT

public:
    explicit TcpServer(QWidget *parent = 0);
    ~TcpServer();

    void initServer();
    void refused();

protected:
    void closeEvent(QCloseEvent *);

private:
    Ui::TcpServer *ui;

    qint16 tcpPort;
    QTcpServer *tcpServer;
    QString fileName;
    QString theFileName;
    QFile *localFile;

    qint64 TotalBytes;
    qint64 bytesWritten;
    qint64 bytesToWrite;
    qint64 payloadSize;
    QByteArray outBlock;

    QTcpSocket *clientConnection;

    QTime time;

private slots:
    void sendMessage();
    void updateClientProgress(qint64 numBytes);

    void on_serverOpenBtn_clicked();

    void on_serverSendBtn_clicked();

    void on_serverCloseBtn_clicked();

};

#endif // TCPSERVER_H
