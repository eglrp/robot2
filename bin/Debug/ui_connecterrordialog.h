/********************************************************************************
** Form generated from reading UI file 'connecterrordialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTERRORDIALOG_H
#define UI_CONNECTERRORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_ConnectErrorDialog
{
public:

    void setupUi(QDialog *ConnectErrorDialog)
    {
        if (ConnectErrorDialog->objectName().isEmpty())
            ConnectErrorDialog->setObjectName(QStringLiteral("ConnectErrorDialog"));
        ConnectErrorDialog->resize(251, 125);

        retranslateUi(ConnectErrorDialog);

        QMetaObject::connectSlotsByName(ConnectErrorDialog);
    } // setupUi

    void retranslateUi(QDialog *ConnectErrorDialog)
    {
        ConnectErrorDialog->setWindowTitle(QApplication::translate("ConnectErrorDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConnectErrorDialog: public Ui_ConnectErrorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTERRORDIALOG_H
