/********************************************************************************
** Form generated from reading UI file 'CoordPassword.ui'
**
** Created: Wed Mar 3 20:48:38 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COORDPASSWORD_H
#define UI_COORDPASSWORD_H

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

class Ui_coorPasswordWidget
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *coorPasswordBox;
    QLabel *label;

    void setupUi(QWidget *coorPasswordWidget)
    {
        if (coorPasswordWidget->objectName().isEmpty())
            coorPasswordWidget->setObjectName(QString::fromUtf8("coorPasswordWidget"));
        coorPasswordWidget->setWindowModality(Qt::WindowModal);
        coorPasswordWidget->resize(403, 212);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(coorPasswordWidget->sizePolicy().hasHeightForWidth());
        coorPasswordWidget->setSizePolicy(sizePolicy);
        coorPasswordWidget->setMinimumSize(QSize(403, 212));
        coorPasswordWidget->setMaximumSize(QSize(403, 212));
        buttonBox = new QDialogButtonBox(coorPasswordWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(0, 150, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(coorPasswordWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 60, 301, 61));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        coorPasswordBox = new QLineEdit(layoutWidget);
        coorPasswordBox->setObjectName(QString::fromUtf8("coorPasswordBox"));

        gridLayout->addWidget(coorPasswordBox, 1, 1, 1, 1);

        label = new QLabel(coorPasswordWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 20, 301, 16));

        retranslateUi(coorPasswordWidget);

        QMetaObject::connectSlotsByName(coorPasswordWidget);
    } // setupUi

    void retranslateUi(QWidget *coorPasswordWidget)
    {
        coorPasswordWidget->setWindowTitle(QApplication::translate("coorPasswordWidget", "Cooper Set Coordinator Password", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("coorPasswordWidget", "Username: ", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("coorPasswordWidget", "admin", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("coorPasswordWidget", "Password: ", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("coorPasswordWidget", "Please enter a password for the Coordinator", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class coorPasswordWidget: public Ui_coorPasswordWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COORDPASSWORD_H
