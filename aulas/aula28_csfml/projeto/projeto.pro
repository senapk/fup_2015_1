TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c
#sudo apt-get install libcsfml-dev libcsfml-audio2
LIBS += -lcsfml-graphics -lcsfml-audio -lcsfml-window

