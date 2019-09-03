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
private slots:
    void on_loginBtn_clicked();

    void on_registerBtn_clicked();

    void connect_success();

private:
    Ui::CheckLoginInput *ui;
    QTcpSocket *tcpSocket;
private slots:
    void onReciveData();
    //void connect();


};


#endif // CHECKLOGININPUT_H
