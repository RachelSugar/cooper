#ifndef LOGIN_H
#define LOGIN_H

#include "../../ui_Login.h"
#include <QString>

class Login {
	
public:
	void runLoginDialog();
	void checkUserInfo(QString name, QString password);
	void displayError();
};

#endif //LOGIN_H
