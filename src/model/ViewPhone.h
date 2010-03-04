#ifndef VIEWPHONE_H
#define VIEWPHONE_H
 
#include "ui_ViewPhone.h"
 
 
class ViewPhone : public QWidget, private Ui::ViewPhoneWidget
{
    Q_OBJECT
 
public:
    ViewPhone(QWidget *parent = 0);
 
public slots:
    void printList();
};
 
 
#endif
