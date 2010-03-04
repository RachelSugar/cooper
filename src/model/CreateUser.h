#ifndef CREATEUSER_H
#define CREATEUSER_H

#include "ui_CreateUser.h"


class CreateUser : public QWidget, private Ui::CreateUser
{
	Q_OBJECT

public:
	CreateUser(QWidget *parent = 0);

public slots:
	void getSave();



};

#endif
