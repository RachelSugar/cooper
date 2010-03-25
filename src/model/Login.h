#ifndef LOGIN_H
#define LOGIN_H

#include "../view/headers/ui_Login.h"
#include <QString>

class Login : public QWidget, private Ui::loginWidget
{
	Q_OBJECT

public:
	Login(QWidget *parent = 0);
	void displayError();

public slots:
	void checkUserInfo();
};

#endif //LOGIN_H
