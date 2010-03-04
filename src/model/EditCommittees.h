#ifndef EDITCOMMITTEES_H
#define EDITCOMMITTEES_H
 
#include "ui_EditCommittees.h"
 
 
class EditCommittees : public QWidget, private Ui::EditCommittees
{
	Q_OBJECT
 
public:
	EditCommittees(QWidget *parent);
 
public slots:
	void editCommittee();
	void deleteCommittee();
};
 
#endif
