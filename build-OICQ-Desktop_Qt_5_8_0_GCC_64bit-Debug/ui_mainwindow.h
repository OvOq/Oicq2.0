/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QStackedWidget *StackWidget;
    QWidget *mainpage;
    QLabel *label;
    QWidget *friendpage;
    QLabel *label_2;
    QWidget *chatpage;
    QLabel *label_3;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1300, 850);
        MainWindow->setMinimumSize(QSize(1300, 850));
        MainWindow->setMaximumSize(QSize(1300, 850));
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(54, 54, 54);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(1300, 850));
        centralWidget->setMaximumSize(QSize(1300, 850));
        centralWidget->setStyleSheet(QStringLiteral("background-color: rgb(46, 52, 54);"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 1131, 851));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        StackWidget = new QStackedWidget(gridLayoutWidget);
        StackWidget->setObjectName(QStringLiteral("StackWidget"));
        StackWidget->setStyleSheet(QStringLiteral("background-color: rgb(79,79,79);"));
        mainpage = new QWidget();
        mainpage->setObjectName(QStringLiteral("mainpage"));
        label = new QLabel(mainpage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(-20, 10, 1131, 831));
        QFont font;
        font.setPointSize(50);
        label->setFont(font);
        StackWidget->addWidget(mainpage);
        friendpage = new QWidget();
        friendpage->setObjectName(QStringLiteral("friendpage"));
        label_2 = new QLabel(friendpage);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(-4, 6, 1131, 841));
        label_2->setFont(font);
        StackWidget->addWidget(friendpage);
        chatpage = new QWidget();
        chatpage->setObjectName(QStringLiteral("chatpage"));
        chatpage->setStyleSheet(QStringLiteral("background-color: rgb(110, 149, 237);"));
        label_3 = new QLabel(chatpage);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(-4, 6, 1131, 841));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral(""));
        StackWidget->addWidget(chatpage);

        gridLayout->addWidget(StackWidget, 0, 0, 1, 1);

        toolButton = new QToolButton(centralWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(1254, 1, 19, 19));
        toolButton->setCursor(QCursor(Qt::PointingHandCursor));
        toolButton->setStyleSheet(QStringLiteral("border-radius:100px;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/image/mini.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton_2 = new QToolButton(centralWidget);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setGeometry(QRect(1279, 1, 19, 19));
        toolButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        toolButton_2->setStyleSheet(QStringLiteral("border-radius:100px;"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/image/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_3 = new QToolButton(centralWidget);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setGeometry(QRect(1150, 80, 98, 92));
        toolButton_3->setCursor(QCursor(Qt::OpenHandCursor));
        toolButton_3->setStyleSheet(QLatin1String("background-color: rgb(108, 123, 139);\n"
"selection-color: rgb(52, 101, 164);\n"
"selection-background-color: rgb(52, 101, 164);\n"
"border-radius:10px;"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/image/main.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon2);
        toolButton_3->setIconSize(QSize(95, 89));
        toolButton_3->setCheckable(true);
        toolButton_3->setAutoExclusive(true);
        toolButton_4 = new QToolButton(centralWidget);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setGeometry(QRect(1150, 280, 98, 92));
        toolButton_4->setCursor(QCursor(Qt::OpenHandCursor));
        toolButton_4->setStyleSheet(QLatin1String("background-color: rgb(108, 123, 139);\n"
"border-radius:10px;"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/image/history.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon3);
        toolButton_4->setIconSize(QSize(95, 89));
        toolButton_5 = new QToolButton(centralWidget);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setGeometry(QRect(1150, 490, 98, 92));
        toolButton_5->setCursor(QCursor(Qt::OpenHandCursor));
        toolButton_5->setStyleSheet(QLatin1String("background-color: rgb(108, 123, 139);\n"
"border-radius:10px;"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix1/image/chat.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon4);
        toolButton_5->setIconSize(QSize(95, 89));
        toolButton_6 = new QToolButton(centralWidget);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        toolButton_6->setGeometry(QRect(1150, 700, 98, 92));
        toolButton_6->setCursor(QCursor(Qt::OpenHandCursor));
        toolButton_6->setStyleSheet(QLatin1String("background-color: rgb(108, 123, 139);\n"
"border-radius:10px;"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/prefix1/image/out.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon5);
        toolButton_6->setIconSize(QSize(95, 89));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "   Welcome", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "        friends", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "       chat", Q_NULLPTR));
        toolButton->setText(QString());
        toolButton_2->setText(QString());
        toolButton_3->setText(QString());
        toolButton_4->setText(QString());
        toolButton_5->setText(QString());
        toolButton_6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
