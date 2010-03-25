#ifndef ADDTASK_H
#define ADDTASK_H
 
#include "../views/headers/ui_AddTask.h"
 
 
class AddTask : public QWidget, private Ui::AddTask
{
	Q_OBJECT
 
public:
	AddTask(QString toAddTo,QWidget *parent);
 
public slots:

	void dateClicked();
	void add();
	static char isTrue(bool toTest);
	
};
 
#endif

