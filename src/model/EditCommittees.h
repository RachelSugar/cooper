#ifndef EDITCOMMITTEES_H
#define EDITCOMMITTEES_H
 
#include "../view/headers/ui_EditCommittees.h"
 
 
class EditCommittees : public QWidget, private Ui::EditCommittees
{
	Q_OBJECT
 
public:
	EditCommittees(QWidget *parent, QString username);
 
public slots:
	void moreInformation();
	void deleteCommittee();
};
 
#endif
