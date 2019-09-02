#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QDialog>

namespace Ui {
class TcpClient;
}

class TcpClient : public QDialog
{
    Q_OBJECT

public:
    explicit TcpClient(QWidget *parent = 0);
    ~TcpClient();

private slots:
    void on_tcpClientStatusLabel_clicked();

    void on_pushButton_2_clicked();

    void on_tcpClientCloseBtn_clicked();

    void on_tcpClientCancleBtn_clicked();

private:
    Ui::TcpClient *ui;
};

#endif // TCPCLIENT_H
