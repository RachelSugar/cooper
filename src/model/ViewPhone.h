#ifndef VIEWPHONE_H
#define VIEWPHONE_H
 
#include "../view/headers/ui_ViewPhone.h"
 
 
class ViewPhone : public QWidget, private Ui::ViewPhoneWidget
{
    Q_OBJECT
 
public:
    ViewPhone(QWidget *parent = 0,bool conf=false);
 
public slots:
	void printList();
	void sortSurname();
	void sortUnit();
	void removeNonResidents();
	void confidentialNumbers();
	void findCohabitants();
	void changeUnits();
};
 
 
#endif
