QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    customerdashboard.cpp \
    fakedatabases.cpp \
    ingredients.cpp \
    kitchendashboard.cpp \
    main.cpp \
    mainwindow.cpp \
    menuitem.cpp \
    order.cpp \
    orderqueue.cpp \
    user.cpp \
    widget_helpers.cpp

HEADERS += \
    fakedatabases.h \
    ingredients.h \
    mainwindow.h \
    menuitem.h \
    order.h \
    orderqueue.h \
    user.h \
    widget_helpers.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
