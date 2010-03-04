#ifndef COORDPASSWORD_H
#define COORDPASSWORD_H

#include "../../ui_CoordPassword.h"
#include <QString>

class CoordPassword : public QWidget, private Ui::coordPasswordWidget
{
	Q_OBJECT

public:
	CoordPassword(QWidget *parent = 0);

public slots:
	void checkPassword();
};

#endif //COORDPASSWORD_H
