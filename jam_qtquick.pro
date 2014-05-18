TEMPLATE = app

QT += qml quick widgets

QMAKE_CXXFLAGS += -std=c++0x -Wunused-parameter

SOURCES += \
    src/main.cpp \
    src/jam/client.cpp \
    src/jam/roster.cpp

RESOURCES += \
    src/qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

LIBS += -L/usr/local/lib/ -lgloox

INCLUDEPATH += /usr/local/include
DEPENDPATH += /usr/local/include

HEADERS += \
    src/jam/client.h \
    src/jam/roster.h
