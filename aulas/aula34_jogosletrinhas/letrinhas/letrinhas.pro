TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    letra.c \
    cenario.c \
    visual.c

LIBS += -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

HEADERS += \
    letra.h \
    cenario.h \
    visual.h
