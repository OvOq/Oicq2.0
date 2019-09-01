#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QUdpSocket;

namespace Ui {
class Widget;
}
//枚举消息，新用户加入，用户退出，文件名，拒绝接收文件五种变量标志信息类型
enum MessageType {Message, NewParticipant, ParticipantLeft, FileName, Refuse};


class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    //新用户加入时要执行的函数的声明
    void newParticipant(QString userName,QString localHostName,QString ipAddress);
    //用户离开时加入时要执行的函数的声明
    void participantLeft(QString userName,QString localHostName,QString time);
    //发消息时要执行的函数的声明
    void sendMessage(MessageType type);

    QString getIP();//获取IP函数的声明
    QString getUserName();//获取用户名函数的声明
    QString getMessage();//获取新消息的函数的声明

private:
    Ui::Widget *ui;
    QUdpSocket *udpSocket;
    qint16 port;

private slots:
    void processPendingDatagrams();//槽函数声明
    void send();//点击发送的槽函数
    void cancel();//点击退出的槽函数
};


#endif // WIDGET_H
