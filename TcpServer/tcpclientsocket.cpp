#include "tcpclientsocket.h"

TcpClientSocket::TcpClientSocket(QObject *parent)
{
    connect(this,SIGNAL(readyRead()),this,SLOT(dataReceived()));
    connect(this,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
}

//接收客户端消息
void TcpClientSocket::dataReceived()
{

    QString msg = this->readAll();
    emit updateClients(msg,msg.length());
}

//客户端断开连接
void TcpClientSocket::slotDisconnected()
{
    emit disconnected(this->socketDescriptor());
}
