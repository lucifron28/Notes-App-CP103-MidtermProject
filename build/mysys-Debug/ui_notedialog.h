/********************************************************************************
** Form generated from reading UI file 'notedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEDIALOG_H
#define UI_NOTEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_NoteDialog
{
public:
    QTextEdit *textEdit;
    QLineEdit *lineEdit;
    QPushButton *saveButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *NoteDialog)
    {
        if (NoteDialog->objectName().isEmpty())
            NoteDialog->setObjectName("NoteDialog");
        NoteDialog->resize(609, 472);
        textEdit = new QTextEdit(NoteDialog);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(130, 90, 361, 311));
        lineEdit = new QLineEdit(NoteDialog);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(130, 50, 361, 41));
        saveButton = new QPushButton(NoteDialog);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(190, 410, 83, 29));
        cancelButton = new QPushButton(NoteDialog);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(350, 410, 83, 29));

        retranslateUi(NoteDialog);

        QMetaObject::connectSlotsByName(NoteDialog);
    } // setupUi

    void retranslateUi(QDialog *NoteDialog)
    {
        NoteDialog->setWindowTitle(QCoreApplication::translate("NoteDialog", "Dialog", nullptr));
        saveButton->setText(QCoreApplication::translate("NoteDialog", "Save", nullptr));
        cancelButton->setText(QCoreApplication::translate("NoteDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NoteDialog: public Ui_NoteDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEDIALOG_H
