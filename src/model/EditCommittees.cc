#include "EditCommittees.h"
#include <QtGui>

EditCommittees::EditCommittees(QWidget *parent){
	setupUi(this);

	connect(DeleteButton,SIGNAL(clicked()), this, SLOT(deleteCommittee()));
	connect(EditButton,SIGNAL(clicked()), this, SLOT(editCommittee()));
	connect(CancelButton,SIGNAL(clicked()), this, SLOT(close()));
}

EditCommittees::editCommittee(){

}

EditCommittees::deleteCommittee(){

}