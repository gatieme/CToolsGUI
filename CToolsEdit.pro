#-------------------------------------------------
#
# Project created by QtCreator 2012-10-13T17:52:14
#
#-------------------------------------------------

QT       += core gui widgets printsupport


# include the qtsingleapplication
include(./qtsingleapplication/src/qtsingleapplication.pri)

TARGET = CToolsGUI
TEMPLATE = app




SOURCES +=  main.cpp                \
            mainwindow.cpp          \
            mdichild.cpp            \
            aboutctools.cpp         \
            mysyntaxhighlighter.cpp \
    qtsystemtrayicon/systemtrayicon.cpp \
    ctoolspackage.cpp

HEADERS  += mainwindow.h            \
            mdichild.h              \
            aboutctools.h           \
            mysyntaxhighlighter.h   \
    qtsystemtrayicon/systemtrayicon.h \
    ctoolspackage.h

FORMS    += mainwindow.ui \
            aboutctools.ui

RESOURCES += \
    MyImages.qrc

RC_FILE += myico.rc


INCLUDEPATH +=  ./qtsystemtrayicon  \
                ./CTools/include


LIBS  +=  -L.\CTools\lib  -lCTools
