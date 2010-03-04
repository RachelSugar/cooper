#ifndef LOGINMODEL_H
#define LOGINMODEL_H

#include "../../ui_Login.h"
#include <QString>

class LoginModel {
	
public:
	bool runLoginDialog();
	bool checkUserInfo(QString name, QString password);
	void displayError();

};

#endif //LOGINMODEL_H