#ifndef EDITUSER_H
#define EDITUSER_H

#include "ui_EditUser.h"


class EditUser : public QWidget, private Ui::EditUser
{
	Q_OBJECT

public:
	EditUser(QWidget *parent = 0, QString usName = "");
	void fillMemberInfo(QString username);
	void fillForEduChair(QString userName);
	void checkIfEducationChair();
	bool checkIfUserExists(QString userName);
	

public slots:
	void getSave();
	void deleteUse();
	void getToEdit();
	
};


#endif
