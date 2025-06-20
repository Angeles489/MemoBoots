##########################################################
# Nombre del ejecutable y configuración de Qt
##########################################################
TEMPLATE = app
TARGET = MemoBoots

QT += core gui widgets
CONFIG += c++17 console
QT += multimedia

##########################################################
# Indicamos la ruta de include/ (para MainWindow.h, etc.)
##########################################################
INCLUDEPATH += $$PWD/include

##########################################################
# Listado de fuentes y cabeceras de nuestro proyecto
##########################################################
SOURCES += \
    src/main.cpp \
    src/MainWindow.cpp \
    src/Card.cpp \
    src/Question.cpp \
    src/TheoryQuestion.cpp \
    src/User.cpp \
    src/WelcomeWindow.cpp

HEADERS += \
    include/MainWindow.h \
    include/Card.h \
    include/Question.h \
    include/TheoryQuestion.h \
    include/User.h \
    include/WelcomeWindow.h