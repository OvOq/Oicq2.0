#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTextCharFormat>

class QUdpSocket;
class TcpServer;

namespace Ui {
class Widget;
}
//????????????????????????????????????
enum MessageType {Message, NewParticipant, ParticipantLeft, FileName, Refuse};


class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    //???????????????
    void newParticipant(QString userName,QString localHostName,QString ipAddress);
    //?????????????????
    void participantLeft(QString userName,QString localHostName,QString time);
    //?????????????
    void sendMessage(MessageType type, QString serverAddress="");

    void hasPendingFile(QString userName, QString serverAddress,
                        QString clientAddress, QString fileName);

    //void bewParticipant(QString userName,QString localHostName,QString ipAddress);//*

    QString getIP();//??IP?????
    QString getUserName();//??????????
    QString getMessage();//???????????

    bool saveFile(const QString&fileName);

    void closeEvent(QCloseEvent*);

private:
    Ui::Widget *ui;
    QUdpSocket *udpSocket;
    qint16 port;
    QColor color;
    QString fileName;
    TcpServer *server;

private slots:
    void processPendingDatagrams();//?????
    void send();//????????
    void cancel();//????????
    void toolButton();//savechast
    void on_fontComboBox_currentFontChanged(QFont f);
    void on_boldToolBtn_clicked(bool checked);
    void on_italicToolBtn_clicked(bool checked);
    void on_underlineToolBtn_clicked(bool checked);
    void on_colorToolBtn_clicked();
    void getFileName(QString);
    void on_sendToolBtn_clicked();
    void on_clearToolBtn_clicked();
    void currentFormatChanged(const QTextCharFormat &format);
    void on_sizeComboBox_currentIndexChanged(QString size);
};


#endif // WIDGET_H
