#-------------------------------------------------
#
# Project created by QtCreator 2019-09-03T22:18:08
#
#-------------------------------------------------

QT       += core gui network quickwidgets opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QSpeedTester
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Linux deploy
# env LD_LIBRARY_PATH="/snap/cqtdeployer/58/lib:/opt/Qt/5.13.0/gcc_64/lib:/usr/local/lib64/" /snap/cqtdeployer/58/bin/cqtdeployer -bin QSpeedTester -qmlDir /home/boris/dev/git/QSpeedTester -qmake /opt/Qt/5.13.0/gcc_64/bin/qmake clear

CONFIG += c++11

SOURCES += \
        controller.cpp \
        main.cpp \
        mainwindow.cpp \
        speedtester.cpp

HEADERS += \
        controller.h \
        mainwindow.h \
        speedtester.h

FORMS += \
        mainwindow.ui

RESOURCES += \
        gauge.qml \
        icons/media-playback-pause.png \
        icons/media-playback-start.png

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    gauge.qml
