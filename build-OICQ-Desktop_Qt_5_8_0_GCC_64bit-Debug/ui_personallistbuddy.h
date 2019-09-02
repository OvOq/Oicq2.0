/********************************************************************************
** Form generated from reading UI file 'personallistbuddy.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONALLISTBUDDY_H
#define UI_PERSONALLISTBUDDY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_personalListBuddy
{
public:

    void setupUi(QWidget *personalListBuddy)
    {
        if (personalListBuddy->objectName().isEmpty())
            personalListBuddy->setObjectName(QStringLiteral("personalListBuddy"));
        personalListBuddy->resize(400, 300);

        retranslateUi(personalListBuddy);

        QMetaObject::connectSlotsByName(personalListBuddy);
    } // setupUi

    void retranslateUi(QWidget *personalListBuddy)
    {
        personalListBuddy->setWindowTitle(QApplication::translate("personalListBuddy", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class personalListBuddy: public Ui_personalListBuddy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONALLISTBUDDY_H
