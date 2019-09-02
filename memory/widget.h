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
    void closeEvent(QCloseEvent*);//  2019/9/2
private:
    Ui::Widget *ui;
    QUdpSocket *udpSocket;
    qint16 port;
    QColor color;

private  slots:
    void processPendingDatagrams();
    void toolButton();
    void on_fontComboBox_currentFontChanged(const QFont &f);
    void on_comboBox_currentIndexChanged(const QString &arg1);
    void on_boldToolBtn_clicked(bool checked);
    void on_italicToolBtn_clicked(bool checked);
    void on_underlineToolBtn_clicked(bool checked);
    void on_colorToolBtn_clicked();
    void on_clearToolBtn_clicked();//2019/9/2
    void on_pushButton_2_clicked();//2019/9/2
    void currentFormatChanged(const QTextCharFormat &format);// 2019/9/2

#endif // WIDGET_H
