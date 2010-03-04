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

SOURCES += src/model/LoginModel.cc
SOURCES += src/model/LoginModel.h

# Views

FORMS += src/view/createUser.ui
FORMS += src/view/Login.ui
FORMS += src/view/CoordPassword.ui
FORMS += src/view/AddNewCommittee.ui
FORMS += src/view/LoginError.ui


# Delegates

# Lib
SOURCES += src/lib/Database.h
SOURCES += src/lib/Database.cc
