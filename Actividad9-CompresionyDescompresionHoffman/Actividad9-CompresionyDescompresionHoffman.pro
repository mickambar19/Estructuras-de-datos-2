TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    ABinario.h \
    Ahoffman.h \
    Codigo.h \
    Dulce.h \
    leerentero.h \
    Letra.h \
    ListaCodigos.h \
    ListaLigada.h \
    NodoArbol.h \
    NodoCodigo.h \
    NodoDoble.h \
    Pila.h

