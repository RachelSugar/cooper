/********************************************************************************
** Form generated from reading UI file 'loginError.ui'
**
** Created: Wed Mar 3 20:42:28 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINERROR_H
#define UI_LOGINERROR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginErrorWidget
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *errorOK;

    void setupUi(QWidget *loginErrorWidget)
    {
        if (loginErrorWidget->objectName().isEmpty())
            loginErrorWidget->setObjectName(QString::fromUtf8("loginErrorWidget"));
        loginErrorWidget->setWindowModality(Qt::WindowModal);
        loginErrorWidget->resize(299, 150);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(loginErrorWidget->sizePolicy().hasHeightForWidth());
        loginErrorWidget->setSizePolicy(sizePolicy);
        loginErrorWidget->setMinimumSize(QSize(299, 150));
        loginErrorWidget->setMaximumSize(QSize(299, 150));
        label = new QLabel(loginErrorWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 10, 201, 51));
        label_2 = new QLabel(loginErrorWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 60, 171, 16));
        errorOK = new QPushButton(loginErrorWidget);
        errorOK->setObjectName(QString::fromUtf8("errorOK"));
        errorOK->setGeometry(QRect(90, 100, 113, 32));

        retranslateUi(loginErrorWidget);

        QMetaObject::connectSlotsByName(loginErrorWidget);
    } // setupUi

    void retranslateUi(QWidget *loginErrorWidget)
    {
        loginErrorWidget->setWindowTitle(QApplication::translate("loginErrorWidget", "Cooper Login Error", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("loginErrorWidget", "You have entered an incorrect ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("loginErrorWidget", "username and password!", 0, QApplication::UnicodeUTF8));
        errorOK->setText(QApplication::translate("loginErrorWidget", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class loginErrorWidget: public Ui_loginErrorWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINERROR_H
