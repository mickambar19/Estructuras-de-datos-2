TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Indice.h \
    leerentero.h \
    ListaDoble.h \
    Nododoble.h \
    Productos.h

