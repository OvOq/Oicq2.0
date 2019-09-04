#ifndef CHECKLOGININPUT_H
#define CHECKLOGININPUT_H

#include <QDialog>
#include "checkregisterinput.h"
#include "ui_checkregisterinput.h"
#include <QTcpSocket>
#include <QMessageBox>

namespace Ui {
class CheckLoginInput;
}

class CheckLoginInput : public QDialog
{
    Q_OBJECT
public:
    explicit CheckLoginInput(QWidget *parent = 0);
    ~CheckLoginInput();
    QString usrname;

private slots:
    void on_loginBtn_clicked();
    void on_registerBtn_clicked();
    void connect_success();
    void onReciveData();


private:
    Ui::CheckLoginInput *ui;
    QTcpSocket *tcpSocket;

};

#endif // CHECKLOGININPUT_H
