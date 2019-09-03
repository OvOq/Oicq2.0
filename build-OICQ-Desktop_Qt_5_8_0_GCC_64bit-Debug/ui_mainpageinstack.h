/********************************************************************************
** Form generated from reading UI file 'mainpageinstack.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPAGEINSTACK_H
#define UI_MAINPAGEINSTACK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_MainPageinStack
{
public:

    void setupUi(QDialog *MainPageinStack)
    {
        if (MainPageinStack->objectName().isEmpty())
            MainPageinStack->setObjectName(QStringLiteral("MainPageinStack"));
        MainPageinStack->resize(400, 300);

        retranslateUi(MainPageinStack);

        QMetaObject::connectSlotsByName(MainPageinStack);
    } // setupUi

    void retranslateUi(QDialog *MainPageinStack)
    {
        MainPageinStack->setWindowTitle(QApplication::translate("MainPageinStack", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainPageinStack: public Ui_MainPageinStack {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGEINSTACK_H
