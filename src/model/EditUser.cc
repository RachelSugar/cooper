#include <QtGui> 
#include "EditUser.h"
#include <QSqlQuery>
// including <QtGui> saves us to include every class user, <QString>, <QFileDialog>,...

EditUser::EditUser(QWidget *parent,bool isCoord)
{
	setupUi(this); // this sets up GUI

	// signals/slots mechanism in action
	
	connect( saveCancel, SIGNAL( rejected() ), this, SLOT( close() ));
	connect( saveCancel, SIGNAL( accepted() ), this, SLOT( getSave() ) ); 
	connect( deleteUser, SIGNAL(clicked() ), this, SLOT( deleteUse() ) );
	connect( getUser, SIGNAL(clicked() ), this, SLOT( getToEdit() ) ); 
	
	if(isCoord == false){
		saveCancel->setEnabled(false);
		deleteUser->setEnabled(false);
	}
	
	
	
	
}


void EditUser::getSave()
{
	//get values of fields in GUI
	QString fName = firstName->text();
	QString lName = lastName->text();
	QString uName = userName->text();
	
	QString tele = telephone->text();
	QString pastAdd = pastAddress->text();
	QString unitx = unit->text();
	QDate movDate = moveInDate->date();
	bool hidden = privateTele->isChecked();
	bool ofAge = over21->isChecked();
	bool mvOut = movedOut->isChecked(); 
	
	//cheap error detection for time being
	if(fName.length() == 0 || lName.length() == 0 || uName.length() == 0 \
		|| tele.length() < 10 || pastAdd.length() == 0 || unitx.length() == 0){
	QMessageBox::critical(0, qApp->tr("Error:"),
			qApp->tr("Please fill in all feilds.\n"),
			QMessageBox::Cancel);
	}
	else{
	
	char phonePublic;
	
	if(hidden == true)
		phonePublic = '0';
	else
		phonePublic = '1';
	
	char age;
		
		if(ofAge == true)
		age = '0';
	else
		age = '1';
	
	char live;	
		if(mvOut == true)
		live = '0';
	else
		live = '1';
		
	QString text = "UPDATE users \
	SET user_name = '" + uName +"', last_name = '" + lName + "', first_name = '" + fName + "', unit_id = '"+ unitx+"', phone_number = '" + tele +"', phone_number_is_public = '" + phonePublic + "', under_twenty = '" + age + "', is_resident = '" + live + "' \
	WHERE user_name = '" + uName +"';";
	//test data
	QSqlQuery query;
	
	qDebug() << "true?" << query.exec(text);
	qDebug() << "first Name = " << fName;
	qDebug() << "last Name = " << lName;
	qDebug() << "username = " << uName;
	
	qDebug() << "tele# = " << tele;
	qDebug() << "pastAddress = " << pastAdd;
	qDebug() << "unit = " << unitx;
	qDebug() << "date = " << movDate;	
	qDebug() << "private? = " << hidden;
	qDebug() << "ofAge? = " << ofAge;
	qDebug() << "mvout? = " << mvOut;
	this->close();
	}
  
}

void EditUser::deleteUse(){

	if(movedOut->isChecked() == true){
		qDebug() << "RAWR DELETE TEH USER";
		QString temp = "DELETE \
		FROM users \
		WHERE user_name = '" + userEdit->text()+ "';";
		QSqlQuery query;
		qDebug() << "true?" << query.exec(temp);
		this->close();
	}
	else{
		QMessageBox::critical(0, qApp->tr("Error:"),
			qApp->tr("Cannot delete user that\nis not moved out.\n"),
			QMessageBox::Cancel);
	
	}
	
	

}

void EditUser::getToEdit(){
	//qDebug() << "blag";
	QString usrName= userEdit->text();
	
	QString answer[14];
	QString text = "SELECT * FROM users WHERE user_name = '" + usrName + "'";
	qDebug() << text;
	qDebug() << usrName;
	QSqlQuery query(text);
	int x;
	while(query.next()){
	
	 	for(x = 0; x < 14; x++){
	  
         answer[x] = query.value(x).toString();
         qDebug() << answer[x] ;
         }
         }
        firstName->setText(answer[5]);
	lastName->setText(answer[4]);
	 userName->setText(answer[2]);
	 userName->setDisabled(true);
	
	if(answer[8] == "0")
		movedOut->setChecked(true);
	else
		movedOut->setChecked(false);
		
	if(answer[11] == "0")
		privateTele->setChecked(true);
	else
		privateTele->setChecked(false);
		
	if(answer[13] == "0")
		over21->setChecked(true);
	else
		over21->setChecked(false);
	
	 telephone->setText(answer[10]);
	// pastAddress->setText();
	 unit->setText(answer[9]);
	// QString text = "SELECT * FROM users WHERE user_name = '" + usrName + "'";
	/* moveInDate->date();
	 bool hidden = privateTele->isChecked();
	 bool ofAge = over21->isChecked();
	 bool mvOut = movedOut->isChecked(); 
         */
         
	
	
	
}





