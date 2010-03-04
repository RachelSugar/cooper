CONFIG += qt debug
QT += sql

# If you want to build an OSX ".app", comment the line below
CONFIG -= app_bundle

OBJECTS_DIR = build/obj
DEST_DIR = build/
MOC_DIR = build/moc

RESOURCES = resources.qrc

# Application
SOURCES += src/Application.cc

# Models

HEADERS += src/model/LoginModel.h
SOURCES += src/model/LoginModel.cc
HEADERS += src/model/CreateUser.h
SOURCES += src/model/CreateUser.cc
HEADERS += src/model/PrototypeMainScreen.h
SOURCES += src/model/PrototypeMainScreen.cc

# Views
FORMS += src/view/PrototypeMainScreen.ui
FORMS += src/view/CreateUser.ui
FORMS += src/view/Login.ui
FORMS += src/view/CoordPassword.ui
FORMS += src/view/AddNewCommittee.ui
FORMS += src/view/LoginError.ui
FORMS += src/view/MemberInformation.ui


# Delegates

# Lib
SOURCES += src/lib/Database.h
SOURCES += src/lib/Database.cc
