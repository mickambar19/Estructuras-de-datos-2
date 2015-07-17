TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    contacto.cpp \
    leerentero.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    contacto.h \
    leerentero.h

