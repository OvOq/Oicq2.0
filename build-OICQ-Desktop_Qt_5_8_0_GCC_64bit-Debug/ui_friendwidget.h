/********************************************************************************
** Form generated from reading UI file 'friendwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDWIDGET_H
#define UI_FRIENDWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_friendwidget
{
public:
    QLabel *label;

    void setupUi(QDialog *friendwidget)
    {
        if (friendwidget->objectName().isEmpty())
            friendwidget->setObjectName(QStringLiteral("friendwidget"));
        friendwidget->resize(681, 491);
        label = new QLabel(friendwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 661, 461));
        QFont font;
        font.setPointSize(30);
        label->setFont(font);

        retranslateUi(friendwidget);

        QMetaObject::connectSlotsByName(friendwidget);
    } // setupUi

    void retranslateUi(QDialog *friendwidget)
    {
        friendwidget->setWindowTitle(QApplication::translate("friendwidget", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("friendwidget", "on friends page,waiting to be changed", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class friendwidget: public Ui_friendwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDWIDGET_H
