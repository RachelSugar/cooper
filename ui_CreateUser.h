/********************************************************************************
** Form generated from reading ui file 'CreateUser.ui'
**
** Created: Wed Mar 3 20:55:23 2010
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
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLineEdit *firstName;
    QLineEdit *lastName;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QTextEdit *pastAddress;
    QLabel *label_4;
    QLineEdit *unit;
    QLabel *label_5;
    QLineEdit *telephone;
    QLabel *label_6;
    QDateEdit *moveInDate;
    QLabel *label_7;
    QLineEdit *userName;
    QLineEdit *password;
    QLabel *label_8;
    QLabel *label_9;
    QDialogButtonBox *accept;
    QLabel *label_10;
    QCheckBox *privateTele;

    void setupUi(QDialog *Dialog)
    {
    if (Dialog->objectName().isEmpty())
        Dialog->setObjectName(QString::fromUtf8("Dialog"));
    Dialog->resize(543, 364);
    firstName = new QLineEdit(Dialog);
    firstName->setObjectName(QString::fromUtf8("firstName"));
    firstName->setGeometry(QRect(20, 80, 181, 29));
    lastName = new QLineEdit(Dialog);
    lastName->setObjectName(QString::fromUtf8("lastName"));
    lastName->setGeometry(QRect(280, 80, 191, 29));
    label_2 = new QLabel(Dialog);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(280, 60, 61, 19));
    label = new QLabel(Dialog);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(20, 60, 61, 19));
    label_3 = new QLabel(Dialog);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setGeometry(QRect(20, 40, 81, 19));
    pastAddress = new QTextEdit(Dialog);
    pastAddress->setObjectName(QString::fromUtf8("pastAddress"));
    pastAddress->setGeometry(QRect(20, 140, 271, 75));
    label_4 = new QLabel(Dialog);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setGeometry(QRect(20, 120, 121, 19));
    unit = new QLineEdit(Dialog);
    unit->setObjectName(QString::fromUtf8("unit"));
    unit->setGeometry(QRect(460, 150, 61, 29));
    label_5 = new QLabel(Dialog);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setGeometry(QRect(460, 110, 71, 41));
    telephone = new QLineEdit(Dialog);
    telephone->setObjectName(QString::fromUtf8("telephone"));
    telephone->setGeometry(QRect(300, 150, 113, 29));
    telephone->setMaxLength(10);
    label_6 = new QLabel(Dialog);
    label_6->setObjectName(QString::fromUtf8("label_6"));
    label_6->setGeometry(QRect(300, 120, 61, 19));
    moveInDate = new QDateEdit(Dialog);
    moveInDate->setObjectName(QString::fromUtf8("moveInDate"));
    moveInDate->setGeometry(QRect(20, 250, 110, 29));
    moveInDate->setDate(QDate(2010, 3, 4));
    label_7 = new QLabel(Dialog);
    label_7->setObjectName(QString::fromUtf8("label_7"));
    label_7->setGeometry(QRect(20, 230, 91, 19));
    userName = new QLineEdit(Dialog);
    userName->setObjectName(QString::fromUtf8("userName"));
    userName->setGeometry(QRect(170, 250, 113, 29));
    password = new QLineEdit(Dialog);
    password->setObjectName(QString::fromUtf8("password"));
    password->setGeometry(QRect(330, 250, 113, 29));
    label_8 = new QLabel(Dialog);
    label_8->setObjectName(QString::fromUtf8("label_8"));
    label_8->setGeometry(QRect(170, 230, 81, 19));
    label_9 = new QLabel(Dialog);
    label_9->setObjectName(QString::fromUtf8("label_9"));
    label_9->setGeometry(QRect(330, 230, 61, 19));
    accept = new QDialogButtonBox(Dialog);
    accept->setObjectName(QString::fromUtf8("accept"));
    accept->setGeometry(QRect(340, 300, 166, 32));
    accept->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
    label_10 = new QLabel(Dialog);
    label_10->setObjectName(QString::fromUtf8("label_10"));
    label_10->setGeometry(QRect(170, 10, 191, 19));
    label_10->setMinimumSize(QSize(191, 0));
    QFont font;
    font.setPointSize(15);
    font.setBold(true);
    font.setUnderline(true);
    font.setWeight(75);
    label_10->setFont(font);
    privateTele = new QCheckBox(Dialog);
    privateTele->setObjectName(QString::fromUtf8("privateTele"));
    privateTele->setGeometry(QRect(300, 180, 121, 25));

    retranslateUi(Dialog);

    QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
    Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
    firstName->setText(QString());
    label_2->setText(QApplication::translate("Dialog", "Last:", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("Dialog", "First", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("Dialog", "Enter Name", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("Dialog", "Pre-Coop Address", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("Dialog", "Unit to \n"
"move  into", 0, QApplication::UnicodeUTF8));
    telephone->setInputMask(QApplication::translate("Dialog", "DDDDDDDDDD; ", 0, QApplication::UnicodeUTF8));
    label_6->setText(QApplication::translate("Dialog", "Tele. #", 0, QApplication::UnicodeUTF8));
    label_7->setText(QApplication::translate("Dialog", "Move in Date", 0, QApplication::UnicodeUTF8));
    label_8->setText(QApplication::translate("Dialog", "User Name", 0, QApplication::UnicodeUTF8));
    label_9->setText(QApplication::translate("Dialog", "Password", 0, QApplication::UnicodeUTF8));
    label_10->setText(QApplication::translate("Dialog", "CREATE MEMBER", 0, QApplication::UnicodeUTF8));
    privateTele->setText(QApplication::translate("Dialog", "Private Tele#?", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Dialog);
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEUSER_H
