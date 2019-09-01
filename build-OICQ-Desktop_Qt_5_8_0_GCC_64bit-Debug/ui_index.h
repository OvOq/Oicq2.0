/********************************************************************************
** Form generated from reading UI file 'index.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INDEX_H
#define UI_INDEX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_index
{
public:
    QLabel *label;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;

    void setupUi(QDialog *index)
    {
        if (index->objectName().isEmpty())
            index->setObjectName(QStringLiteral("index"));
        index->resize(1002, 714);
        index->setStyleSheet(QStringLiteral("background-color: rgb(54, 54, 54);"));
        label = new QLabel(index);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 861, 711));
        label->setStyleSheet(QStringLiteral("background-color: rgb(28, 28, 28);"));
        toolButton = new QToolButton(index);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(880, 160, 111, 111));
        toolButton->setStyleSheet(QLatin1String("background-color: rgb(108, 123, 139);\n"
"border-radius:10px;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/image/main.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(70, 70));
        toolButton_2 = new QToolButton(index);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setGeometry(QRect(880, 300, 111, 101));
        toolButton_2->setStyleSheet(QLatin1String("background-color: rgb(108, 123, 139);\n"
"border-radius:10px;"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/image/friend.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setIconSize(QSize(70, 70));
        toolButton_3 = new QToolButton(index);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setGeometry(QRect(880, 430, 111, 101));
        toolButton_3->setStyleSheet(QLatin1String("background-color: rgb(108, 123, 139);\n"
"border-radius:10px;"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/image/chat.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon2);
        toolButton_3->setIconSize(QSize(90, 90));
        toolButton_4 = new QToolButton(index);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setGeometry(QRect(880, 560, 111, 101));
        toolButton_4->setStyleSheet(QLatin1String("background-color: rgb(108, 123, 139);\n"
"border-radius:10px;"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/image/out.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon3);
        toolButton_4->setIconSize(QSize(80, 80));
        toolButton_5 = new QToolButton(index);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        toolButton_5->setGeometry(QRect(940, 10, 26, 24));
        toolButton_5->setStyleSheet(QStringLiteral("border-radius:100px;"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix1/image/mini.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon4);
        toolButton_6 = new QToolButton(index);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        toolButton_6->setGeometry(QRect(970, 10, 26, 24));
        toolButton_6->setStyleSheet(QStringLiteral("border-radius:100px;"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/prefix1/image/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon5);

        retranslateUi(index);

        QMetaObject::connectSlotsByName(index);
    } // setupUi

    void retranslateUi(QDialog *index)
    {
        index->setWindowTitle(QApplication::translate("index", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("index", "Welcome", Q_NULLPTR));
        toolButton->setText(QApplication::translate("index", "...", Q_NULLPTR));
        toolButton_2->setText(QApplication::translate("index", "...", Q_NULLPTR));
        toolButton_3->setText(QApplication::translate("index", "...", Q_NULLPTR));
        toolButton_4->setText(QApplication::translate("index", "...", Q_NULLPTR));
        toolButton_5->setText(QApplication::translate("index", "...", Q_NULLPTR));
        toolButton_6->setText(QApplication::translate("index", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class index: public Ui_index {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDEX_H
