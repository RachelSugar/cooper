#include "User.h"

#include "Committee.h"
#include "Unit.h"


#ifndef FRESH_ID
#define FRESH_ID 0
#endif

User::User()
{
        _id                  = FRESH_ID;
        _userName            = "";
        _password            = "";
        _firstName           = "";
        _lastName            = "";
        _isCoordinator       = false;
        _is21                = false;
        _committeeId         = 0;
        _isResident          = false;
        _unitId              = 0;
        _phoneNumber         = "";
        _phoneNumberIsPublic = false;
        _inArrears           = false;
        _oldAddress          = "";
        _moveInDate          = QDate::currentDate();
}

User::User(QSqlQuery query)
{
	_id                  = query.value(0).toInt();
	_userName            = query.value(1).toString();
	_password            = query.value(2).toString();
	_firstName           = query.value(3).toString();
	_lastName            = query.value(4).toString();
	_isCoordinator       = query.value(5).toBool();
	_is21                = query.value(6).toBool();
	_committeeId         = query.value(7).toInt();
	_isResident          = query.value(8).toBool();
	_unitId              = query.value(9).toInt();
	_phoneNumber         = query.value(10).toString();
	_phoneNumberIsPublic = query.value(11).toBool();
	_inArrears           = query.value(12).toBool();
	_oldAddress          = query.value(13).toString();
	_moveInDate          = query.value(14).toDate();
}

int User::id()
{
        return _id;
}

QString User::firstName()
{
        return _firstName;
}

void User::setFirstName(QString firstName)
{
        _firstName = firstName;
}

QString User::lastName()
{
        return _lastName;
}

void User::setLastName(QString lastName)
{
        _lastName = lastName;
}

QString User::fullName()
{
        return _firstName + " " + _lastName;
}

QString User::userName()
{
        return _userName;
}

void User::setUserName(QString userName)
{
        _userName = userName;
}

QString User::password()
{
        return _password;
}

void User::setPassword(QString password)
{
        _password = password;
}

bool User::isCoordinator()
{
        return _isCoordinator;
}

void User::setIsCoordinator(bool isCoordinator)
{
        _isCoordinator = isCoordinator;
}

bool User::is21()
{
        return _is21;
}

void User::setIs21(bool is21)
{
        _is21 = is21;
}

Committee User::committee()
{
        return Committee::find(_committeeId);
}

void User::setCommittee(Committee committee)
{
        _committeeId = committee.id();
}

bool User::isResident()
{
        return _isResident;
}

void User::setIsResident(bool isResident)
{
        _isResident = isResident;
}

Unit User::unit()
{
        return Unit::find(_unitId);
}

void User::setUnit(Unit unit)
{
        _unitId = unit.id();
}

QString User::phoneNumber()
{
        return _phoneNumber;
}

void User::setPhoneNumber(QString phoneNumber)
{
        _phoneNumber = phoneNumber;
}

bool User::phoneNumberIsPublic()
{
        return _phoneNumberIsPublic;
}

void User::setPhoneNumberIsPublic(bool phoneNumberIsPublic)
{
        _phoneNumberIsPublic = phoneNumberIsPublic;
}

bool User::inArrears()
{
        return _inArrears;
}

void User::setInArrears(bool inArrears)
{
        _inArrears = inArrears;
}

QString User::oldAddress()
{
        return _oldAddress;
}

void User::setOldAddress(QString oldAddress)
{
        _oldAddress = oldAddress;
}

QDate User::moveInDate()
{
        return _moveInDate;
}

void User::setMoveInDate(QDate moveInDate)
{
        _moveInDate = moveInDate;
}


bool User::save()
{
	QSqlQuery query;
        // Use INSERT/UPDATE depending on if the user is new or not
	if ( _id != FRESH_ID ) {
	        query.prepare("UPDATE users SET user_name=:user_name, password=:password, first_name=:first_name, last_name=:last_name, is_coordinator=:is_coordinator, is_21=:is_21, committee_id=:committee_id, is_resident=:is_resident, unit_id=:unit_id, phone_number=:phone_number, phone_number_is_public=:phone_number_is_public, in_arrears=:in_arrears, old_address=:old_address, move_in_date=:move_in_date WHERE id=:id");
                query.bindValue(":id", _id);
	} else {
                query.prepare("INSERT INTO users VALUES (:id, :user_name, :password, :first_name, :last_name, :is_coordinator, :is_21, :committee_id, :is_resident, :unit_id, :phone_number, :phone_number_is_public, :in_arrears, :old_address, :move_in_date)");
	}
        query.bindValue(":user_name", _userName);
        query.bindValue(":password", _password);
        query.bindValue(":first_name", _firstName);
        query.bindValue(":last_name", _lastName);
        query.bindValue(":is_coordinator", _isCoordinator);
        query.bindValue(":is_21", _is21);
        query.bindValue(":committee_id", _committeeId);
        query.bindValue(":is_resident", _isResident);
        query.bindValue(":unit_id", _unitId);
        query.bindValue(":phone_number", _phoneNumber);
        query.bindValue(":phone_number_is_public", _phoneNumberIsPublic);
        query.bindValue(":in_arrears", _inArrears);
        query.bindValue(":old_address", _oldAddress);
        query.bindValue(":move_in_date", _moveInDate);
        return query.exec();
}

User User::find(int id)
{
	QSqlQuery query;
	query.exec("SELECT id, user_name, password, first_name, last_name, is_coordinator, is_21, committee_id, is_resident, unit_id, phone_number, phone_number_is_public, in_arrears, old_address, move_in_date FROM users WHERE id="
                        + QVariant(id).toString());
	query.next();
	User u(query);
	return u;
}

QList<User> User::findWhere(QString conditions)
{
	QSqlQuery query;
	query.exec("SELECT id, user_name, password, first_name, last_name, is_coordinator, is_21, committee_id, is_resident, unit_id, phone_number, phone_number_is_public, in_arrears, old_address, move_in_date FROM users WHERE " + conditions);
	User *u;
	QList<User> results;
	while(query.next()) {
		u = new User(query);
		results << *u;
	}
	return results;
}

QList<User> User::all()
{
	QSqlQuery query;
	query.exec("SELECT id, user_name, password, first_name, last_name, is_coordinator, is_21, committee_id, is_resident, unit_id, phone_number, phone_number_is_public, in_arrears, old_address, move_in_date FROM users");
	User *u;
	QList<User> results;
	while(query.next()) {
		u = new User(query);
		results << *u;
	}
	return results;
}