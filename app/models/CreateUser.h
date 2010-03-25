#ifndef CREATEUSER_H
#define CREATEUSER_H

#include "../views/headers/ui_CreateUser.h"


class CreateUser : public QWidget, private Ui::CreateUser
{
	Q_OBJECT

public:
	CreateUser(QWidget *parent = 0);
	

public slots:
	void getSave();
	static char isTrue(bool toTest);
	static char isTrue2(bool toTest);
};

#endif
