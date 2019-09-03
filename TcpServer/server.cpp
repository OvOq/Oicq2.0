#include "server.h"

Server::Server(QObject *parent,int port):QTcpServer(parent)
{
    listen(QHostAddress::Any,port);
}

//重载incomingConnection函数
void Server::incomingConnection(int socketDescriptor)
{
    TcpClientSocket *tcpClientSocket=new TcpClientSocket(this);

    connect(tcpClientSocket,SIGNAL(updateClients(QString,int)),
            this,SLOT(updateClients(QString,int)));
    connect(tcpClientSocket,SIGNAL(disconnected(int)),this,
            SLOT(slotDisconnected(int)));
    tcpClientSocket->setSocketDescriptor(socketDescriptor);

    tcpClientSocketList.append(tcpClientSocket); //加入客户端socket列表
}

//返回确认信息并写在服务端面板上
void Server::updateClients(QString msg,int length)
{


    emit updateServer(msg,length);

    /*for(int i=0;i<tcpClientSocketList.count();i++)
    {
        QTcpSocket *item = tcpClientSocketList.at(i);
        if(item->write(msg.toLatin1(),length)!=length)
        {
            continue;
        }
    }*/
}

void Server::check_result(QString result)
{
    for(int i=0;i<tcpClientSocketList.count();i++)
    {
       TcpClientSocket *item = tcpClientSocketList.at(i);
       QByteArray _result = result.toLatin1();
       item->write(_result);

    }
}

//断开连接
void Server::slotDisconnected(int descriptor)
{
    for(int i=0;i<tcpClientSocketList.count();i++)
    {
        QTcpSocket *item = tcpClientSocketList.at(i);
        if(item->socketDescriptor()==descriptor)
        {
            tcpClientSocketList.removeAt(i);
            return;
        }
    }
    return;
}
