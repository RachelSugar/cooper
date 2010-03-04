#include <QtGui> 
#include "CreateUser.h"

// including <QtGui> saves us to include every class user, <QString>, <QFileDialog>,...

CreateUser::CreateUser(QWidget *parent)
{
	setupUi(this); // this sets up GUI

	// signals/slots mechanism in action
	
	connect( saveCancel, SIGNAL( rejected() ), this, SLOT( close() ));
	connect( saveCancel, SIGNAL( accepted() ), this, SLOT( getSave() ) ); 
	
}


void CreateUser::getSave()
{
	//get values of fields in GUI
	QString fName = firstName->text();
	QString lName = lastName->text();
	QString uName = userName->text();
	QString pass = password->text();
	QString tele = telephone->text();
	QString pastAdd = pastAddress->text();
	QString unitx = unit->text();
	QDate movDate = moveInDate->date();
	bool hidden = privateTele->isChecked();
	
	//cheap error detection for time being
	if(fName.length() == 0 || lName.length() == 0 || uName.length() == 0 || pass.length() == 0 \
		|| tele.length() < 10 || pastAdd.length() == 0 || unitx.length() == 0){
	QMessageBox::critical(0, qApp->tr("Error:"),
			qApp->tr("Please fill in all feilds.\n"),
			QMessageBox::Cancel);
	}
	
	//test data
	qDebug() << "first Name = " << fName;
	qDebug() << "last Name = " << lName;
	qDebug() << "username = " << uName;
	qDebug() << "password = " << pass;
	qDebug() << "tele# = " << tele;
	qDebug() << "pastAddress = " << pastAdd;
	qDebug() << "unit = " << unitx;
	qDebug() << "date = " << movDate;	
	qDebug() << "private? = " << hidden;	
  
}





