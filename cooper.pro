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

# Views
FORMS += login.ui

# Delegates

# Lib
SOURCES += src/lib/Database.h
SOURCES += src/lib/Database.cc
