/********************************************************************************
** Form generated from reading UI file 'AddNewCommittee.ui'
**
** Created: Wed Mar 3 20:42:28 2010
**      by: Qt User Interface Compiler version 4.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNEWCOMMITTEE_H
#define UI_ADDNEWCOMMITTEE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddNewCommittee
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QComboBox *comboBox;
    QLabel *label_4;
    QComboBox *comboBox_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *AddNewCommittee)
    {
        if (AddNewCommittee->objectName().isEmpty())
            AddNewCommittee->setObjectName(QString::fromUtf8("AddNewCommittee"));
        AddNewCommittee->setWindowModality(Qt::ApplicationModal);
        AddNewCommittee->resize(321, 169);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddNewCommittee->sizePolicy().hasHeightForWidth());
        AddNewCommittee->setSizePolicy(sizePolicy);
        layoutWidget = new QWidget(AddNewCommittee);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 11, 300, 151));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 2);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaxLength(120);

        gridLayout->addWidget(lineEdit, 1, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 2, 1, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        comboBox_2 = new QComboBox(layoutWidget);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 3, 1, 1, 1);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setLayoutDirection(Qt::LeftToRight);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        buttonBox->setCenterButtons(false);

        gridLayout->addWidget(buttonBox, 4, 1, 1, 1);


        retranslateUi(AddNewCommittee);
        QObject::connect(buttonBox, SIGNAL(rejected()), AddNewCommittee, SLOT(close()));

        QMetaObject::connectSlotsByName(AddNewCommittee);
    } // setupUi

    void retranslateUi(QWidget *AddNewCommittee)
    {
        AddNewCommittee->setWindowTitle(QApplication::translate("AddNewCommittee", "Adding New Committee", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AddNewCommittee", "Enter the information for the new committee:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AddNewCommittee", "Committee name", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QString());
        label_3->setText(QApplication::translate("AddNewCommittee", "Chair (optional)", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AddNewCommittee", "Secretary (optional)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddNewCommittee: public Ui_AddNewCommittee {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNEWCOMMITTEE_H
