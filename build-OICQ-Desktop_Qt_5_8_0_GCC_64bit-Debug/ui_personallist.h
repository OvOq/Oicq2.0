/********************************************************************************
** Form generated from reading UI file 'personallist.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONALLIST_H
#define UI_PERSONALLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_personalList
{
public:

    void setupUi(QWidget *personalList)
    {
        if (personalList->objectName().isEmpty())
            personalList->setObjectName(QStringLiteral("personalList"));
        personalList->resize(400, 300);

        retranslateUi(personalList);

        QMetaObject::connectSlotsByName(personalList);
    } // setupUi

    void retranslateUi(QWidget *personalList)
    {
        personalList->setWindowTitle(QApplication::translate("personalList", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class personalList: public Ui_personalList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONALLIST_H
