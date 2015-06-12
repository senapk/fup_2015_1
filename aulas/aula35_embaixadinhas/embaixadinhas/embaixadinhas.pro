TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c

LIBS += -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio
