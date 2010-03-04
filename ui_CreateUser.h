/********************************************************************************
** Form generated from reading ui file 'CreateUser.ui'
**
** Created: Wed Mar 3 22:43:53 2010
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CREATEUSER_H
#define UI_CREATEUSER_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateUser
{
public:
    QLabel *label_2;
    QLineEdit *userName;
    QLabel *label_3;
    QDialogButtonBox *saveCancel;
    QLineEdit *firstName;
    QLineEdit *lastName;
    QLineEdit *telephone;
    QLineEdit *unit;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *password;
    QDateEdit *moveInDate;
    QLabel *label_9;
    QCheckBox *privateTele;
    QLabel *label_5;
    QLabel *label_10;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *pastAddress;

    void setupUi(QWidget *CreateUser)
    {
    if (CreateUser->objectName().isEmpty())
        CreateUser->setObjectName(QString::fromUtf8("CreateUser"));
    CreateUser->resize(546, 376);
    label_2 = new QLabel(CreateUser);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(280, 70, 61, 19));
    userName = new QLineEdit(CreateUser);
    userName->setObjectName(QString::fromUtf8("userName"));
    userName->setGeometry(QRect(170, 260, 113, 29));
    label_3 = new QLabel(CreateUser);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setGeometry(QRect(20, 50, 81, 19));
    saveCancel = new QDialogButtonBox(CreateUser);
    saveCancel->setObjectName(QString::fromUtf8("saveCancel"));
    saveCancel->setGeometry(QRect(340, 310, 166, 32));
    saveCancel->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
    firstName = new QLineEdit(CreateUser);
    firstName->setObjectName(QString::fromUtf8("firstName"));
    firstName->setGeometry(QRect(20, 90, 181, 29));
    lastName = new QLineEdit(CreateUser);
    lastName->setObjectName(QString::fromUtf8("lastName"));
    lastName->setGeometry(QRect(280, 90, 191, 29));
    telephone = new QLineEdit(CreateUser);
    telephone->setObjectName(QString::fromUtf8("telephone"));
    telephone->setGeometry(QRect(300, 160, 111, 31));
    telephone->setMaxLength(10);
    unit = new QLineEdit(CreateUser);
    unit->setObjectName(QString::fromUtf8("unit"));
    unit->setGeometry(QRect(460, 160, 61, 29));
    label_7 = new QLabel(CreateUser);
    label_7->setObjectName(QString::fromUtf8("label_7"));
    label_7->setGeometry(QRect(20, 240, 91, 19));
    label_8 = new QLabel(CreateUser);
    label_8->setObjectName(QString::fromUtf8("label_8"));
    label_8->setGeometry(QRect(170, 240, 81, 19));
    password = new QLineEdit(CreateUser);
    password->setObjectName(QString::fromUtf8("password"));
    password->setGeometry(QRect(330, 260, 113, 29));
    moveInDate = new QDateEdit(CreateUser);
    moveInDate->setObjectName(QString::fromUtf8("moveInDate"));
    moveInDate->setGeometry(QRect(20, 260, 110, 29));
    moveInDate->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
    moveInDate->setDate(QDate(2010, 3, 4));
    label_9 = new QLabel(CreateUser);
    label_9->setObjectName(QString::fromUtf8("label_9"));
    label_9->setGeometry(QRect(330, 240, 61, 19));
    privateTele = new QCheckBox(CreateUser);
    privateTele->setObjectName(QString::fromUtf8("privateTele"));
    privateTele->setGeometry(QRect(300, 190, 121, 25));
    label_5 = new QLabel(CreateUser);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setGeometry(QRect(460, 120, 71, 41));
    label_10 = new QLabel(CreateUser);
    label_10->setObjectName(QString::fromUtf8("label_10"));
    label_10->setGeometry(QRect(170, 20, 191, 19));
    label_10->setMinimumSize(QSize(191, 0));
    QFont font;
    font.setPointSize(15);
    font.setBold(true);
    font.setUnderline(true);
    font.setWeight(75);
    label_10->setFont(font);
    label = new QLabel(CreateUser);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(20, 70, 61, 19));
    label_4 = new QLabel(CreateUser);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setGeometry(QRect(20, 130, 121, 19));
    label_6 = new QLabel(CreateUser);
    label_6->setObjectName(QString::fromUtf8("label_6"));
    label_6->setGeometry(QRect(300, 130, 61, 19));
    pastAddress = new QLineEdit(CreateUser);
    pastAddress->setObjectName(QString::fromUtf8("pastAddress"));
    pastAddress->setGeometry(QRect(20, 150, 251, 81));

    retranslateUi(CreateUser);

    QMetaObject::connectSlotsByName(CreateUser);
    } // setupUi

    void retranslateUi(QWidget *CreateUser)
    {
    CreateUser->setWindowTitle(QApplication::translate("CreateUser", "Form", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("CreateUser", "Last:", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("CreateUser", "Enter Name", 0, QApplication::UnicodeUTF8));
    firstName->setText(QString());
    telephone->setInputMask(QApplication::translate("CreateUser", "DDDDDDDDDD; ", 0, QApplication::UnicodeUTF8));
    label_7->setText(QApplication::translate("CreateUser", "Move in Date", 0, QApplication::UnicodeUTF8));
    label_8->setText(QApplication::translate("CreateUser", "User Name", 0, QApplication::UnicodeUTF8));
    label_9->setText(QApplication::translate("CreateUser", "Password", 0, QApplication::UnicodeUTF8));
    privateTele->setText(QApplication::translate("CreateUser", "Private Tele?", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("CreateUser", "Unit to \n"
"move  into", 0, QApplication::UnicodeUTF8));
    label_10->setText(QApplication::translate("CreateUser", "CREATE MEMBER", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("CreateUser", "First", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("CreateUser", "Pre-Coop Address", 0, QApplication::UnicodeUTF8));
    label_6->setText(QApplication::translate("CreateUser", "Tele. ", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(CreateUser);
    } // retranslateUi

};

namespace Ui {
    class CreateUser: public Ui_CreateUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEUSER_H
