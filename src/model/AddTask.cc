#include "AddTask.h"
#include <QtGui>
#include <QtSql>
#include <QItemSelectionModel>
#include <QModelIndex>

QString committee;

AddTask::AddTask(QString toAddTo){
	setupUi(this);
	
	committee = toAddTo;
	connect(cancelOk,SIGNAL(rejected()), this, SLOT(close()));
	connect(cancelOk,SIGNAL(accepted()), this, SLOT(add()));
	connect(dueDateCheck,SIGNAL(clicked()), this, SLOT(dateClicked()));
	

}

void AddTask::dateClicked(){
	bool isCheck = dueDateCheck->isChecked();
	
	if(isCheck == true){
		dateBox->setEnabled(true);
	}
	else{
		dateBox->setEnabled(false);
	}
}

void AddTask::add(){

}

