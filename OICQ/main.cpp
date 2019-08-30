#include "mainwindow.h"
#include <QApplication>
#include "checklogininput.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    /*以下是登录页面*/
    CheckLoginInput dlg;
    if (dlg.exec() == QDialog::Accepted)
    {
        w.show();//展示MainWindow
        return a.exec();
    }
    else
        return 0;
}
