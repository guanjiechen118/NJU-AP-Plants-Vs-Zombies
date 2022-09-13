#-------------------------------------------------
#
# Project created by QtCreator 2021-11-11T17:34:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pvz_v2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        playsence.cpp \
    sun.cpp \
    plant.cpp \
    sunflower.cpp \
    grass.cpp \
    zombies.cpp \
    clever_zombie.cpp \
    nutwall.cpp \
    bullet.cpp \
    peashooter.cpp \
    spikerock.cpp \
    car.cpp \
    repeater.cpp \
    firetree.cpp \
    cherrybomb.cpp \
    airzombie.cpp \
    card.cpp \
    starfruit.cpp \
    star.cpp

HEADERS += \
        playsence.h \
    sun.h \
    plant.h \
    sunflower.h \
    grass.h \
    zombies.h \
    clever_zombie.h \
    nutwall.h \
    bullet.h \
    peashooter.h \
    spikerock.h \
    car.h \
    repeater.h \
    firetree.h \
    cherrybomb.h \
    airzombie.h \
    card.h \
    starfruit.h

FORMS += \
        playsence.ui

RESOURCES += \
    ../resource/rc/res.qrc

DISTFILES += \
    ../resource/rc/Starfruit.gif \
    ../resource/rc/Star.gif \
    ../resource/rc/Starfruit.gif \
    ../resource/rc/ZombiesWon.png \
    ../resource/rc/ZombieNote1.png
