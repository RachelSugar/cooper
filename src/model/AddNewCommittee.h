#ifndef ADDNEWCOMMITTEE_H
#define ADDNEWCOMMITTEE_H
 
#include "../view/headers/ui_AddNewCommittee.h"
 
 
class AddNewCommittee : public QWidget, private Ui::AddCommitteeDialog
{
	Q_OBJECT
 
public:
	AddNewCommittee(QWidget *parent = 0);
 
 
public slots:
	void save();
};
 
 
#endif
