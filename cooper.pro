CONFIG += qt debug
QT += sql

QMAKE_CLEAN += cooperDB.sqlite3 db/cooperDB.sqlite3

# If you want to build an OSX ".app", comment the line below
CONFIG -= app_bundle

OBJECTS_DIR = build/obj
DEST_DIR = build/
MOC_DIR = build/moc

RESOURCES = resources.qrc

# Application
SOURCES += src/Application.cc

# Models

HEADERS += src/model/Login.h
SOURCES += src/model/Login.cc
HEADERS += src/model/CoordPassword.h
SOURCES += src/model/CoordPassword.cc
HEADERS += src/model/CreateUser.h
SOURCES += src/model/CreateUser.cc
HEADERS += src/model/EditUser.h
SOURCES += src/model/EditUser.cc
HEADERS += src/model/ViewPhone.h
SOURCES += src/model/ViewPhone.cc
HEADERS += src/model/PrototypeMainScreen.h
SOURCES += src/model/PrototypeMainScreen.cc
HEADERS += src/model/AddNewCommittee.h
SOURCES += src/model/AddNewCommittee.cc
HEADERS += src/model/EditCommittees.h
SOURCES += src/model/EditCommittees.cc

# Views
FORMS += src/view/PrototypeMainScreen.ui
FORMS += src/view/EditUser.ui
FORMS += src/view/CreateUser.ui
FORMS += src/view/Login.ui
FORMS += src/view/CoordPassword.ui
FORMS += src/view/AddNewCommittee.ui
FORMS += src/view/MemberInformation.ui
FORMS += src/view/ViewPhone.ui
FORMS += src/view/EditCommittees.ui

# Delegates

# Lib
HEADERS += src/lib/Database.h
SOURCES += src/lib/Database.cc
