#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QDialog>
#include <QListWidget>
#include <QStackedWidget>
#include <QLabel>
#include <mainpageinstack.h>
#include "checklogininput.h"
#include "friendwidget.h"
#include "widget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    // mission board settings
    QSystemTrayIcon *trayIcon;
    QMenu *trayMenu;
    QAction *quitAction;
    QAction *restoreWinAction;

    void createMenu();

    // stack window init
    MainPageinStack *mainpagewidget;
    friendwidget *friendpage;
    Widget *chatpage;

    // log out and back to login window
    CheckLoginInput *log_i;

private Q_SLOTS:
    void condButtonPressed();

private slots:
    void on_toolButton_2_clicked();
    void on_toolButton_clicked();
    void on_toolButton_3_clicked();
    void on_toolButton_4_clicked();
    void on_toolButton_5_clicked();
};

#endif // MAINWINDOW_H
