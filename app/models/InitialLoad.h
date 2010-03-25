#ifndef INITIALLOAD_H
#define INITIALLOAD_H

#include "../views/headers/ui_CoordPassword.h"
#include <QString>


class InitialLoad : public QWidget, private Ui::coordPasswordWidget
{
	Q_OBJECT

public:
	InitialLoad(QWidget *parent = 0);
	bool bulkLoadFile();
	void loadInData(QString fileLoc);
	void showError(char *message);

public slots:
	void checkPassword();
};

#endif //INITIALLOAD_H
