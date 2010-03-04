/********************************************************************************
** Form generated from reading UI file 'Login.ui'
**
** Created: Wed Mar 3 20:48:38 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginWidget
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *usernameBox;
    QLabel *passwordLabel;
    QLineEdit *passwordBox;
    QLabel *userNameLabel;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *loginWidget)
    {
        if (loginWidget->objectName().isEmpty())
            loginWidget->setObjectName(QString::fromUtf8("loginWidget"));
        loginWidget->setWindowModality(Qt::WindowModal);
        loginWidget->resize(397, 205);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(loginWidget->sizePolicy().hasHeightForWidth());
        loginWidget->setSizePolicy(sizePolicy);
        loginWidget->setMinimumSize(QSize(397, 205));
        loginWidget->setMaximumSize(QSize(397, 205));
        layoutWidget = new QWidget(loginWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 30, 341, 91));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        usernameBox = new QLineEdit(layoutWidget);
        usernameBox->setObjectName(QString::fromUtf8("usernameBox"));
        usernameBox->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(usernameBox, 0, 1, 1, 1);

        passwordLabel = new QLabel(layoutWidget);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(passwordLabel, 1, 0, 1, 1);

        passwordBox = new QLineEdit(layoutWidget);
        passwordBox->setObjectName(QString::fromUtf8("passwordBox"));
        passwordBox->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(passwordBox, 1, 1, 1, 1);

        userNameLabel = new QLabel(layoutWidget);
        userNameLabel->setObjectName(QString::fromUtf8("userNameLabel"));
        userNameLabel->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(userNameLabel, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(loginWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(20, 140, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(loginWidget);

        QMetaObject::connectSlotsByName(loginWidget);
    } // setupUi

    void retranslateUi(QWidget *loginWidget)
    {
        loginWidget->setWindowTitle(QApplication::translate("loginWidget", "Cooper Login", 0, QApplication::UnicodeUTF8));
        passwordLabel->setText(QApplication::translate("loginWidget", "Password ", 0, QApplication::UnicodeUTF8));
        userNameLabel->setText(QApplication::translate("loginWidget", "Username ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class loginWidget: public Ui_loginWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
