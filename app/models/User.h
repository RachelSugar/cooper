#ifndef USER_H
#define USER_H

#include <QObject>
#include <QString>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QList>
#include <QDate>

// Forward declarations
class Committee;
class Unit;

class User
{
public:
	User();
	int id();
	QString firstName();
	void setFirstName(QString firstName);
	QString lastName();
	void setLastName(QString lastName);
        QString fullName();
        QString userName();
        void setUserName(QString userName);
        QString password();
        void setPassword(QString userName);
        bool isCoordinator();
        void setIsCoordinator(bool isCoordinator);
        bool is21();
        void setIs21(bool is21);
        Committee committee();
        void setCommittee(Committee committee);
        bool isResident();
        void setIsResident(bool isResident);
        Unit unit();
        void setUnit(Unit unit);
        QString phoneNumber();
        void setPhoneNumber(QString phoneNumber);
        bool phoneNumberIsPublic();
        void setPhoneNumberIsPublic(bool phoneNumberIsPublic);
        bool inArrears();
        void setInArrears(bool inArrears);
        QString oldAddress();
        void setOldAddress(QString oldAddress);
        QDate moveInDate();
        void setMoveInDate(QDate moveInDate);
	bool save();
	static User find(int id);
	static QList<User> findWhere(QString conditions);
	static QList<User> all();
private:
	User(QSqlQuery query);
	int _id;
        QString _firstName;
        QString _lastName;
        QString _userName;
        QString _password;
        bool _isCoordinator;
        bool _is21;
        int _committeeId;
        bool _isResident;
        int _unitId;
        QString _phoneNumber;
        bool _phoneNumberIsPublic;
        bool _inArrears;
        QString _oldAddress;
        QDate _moveInDate;
};

#endif // USER_H
