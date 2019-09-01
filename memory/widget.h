#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QUdpSocket;
namespace Ui {
class Widget;
}

enum MessageType{Message,NewParticipant,ParticipantLeft,FileName,Refuse};
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void bewParticipant(QString userName,QString localHostName,QString ipAddress);
    void participantLeft(QString userName,QString localHostName,QString time);
    void sendmessgae(MessageType type,QString serverAddress="");
    QString getIP();
    QString getUserName();
    QString getMessgae();
    bool saveFile(const QString&fileName);

private:
    Ui::Widget *ui;
    QUdpSocket *udpSocket;
    qint16 port;

private  slots:
    void processPendingDatagrams();
    void toolButton();
};

#endif // WIDGET_H
