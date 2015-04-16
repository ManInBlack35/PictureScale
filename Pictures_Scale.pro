TEMPLATE = app
QT = core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG -= app_bundle

SOURCES += main.cpp \
    dialog.cpp \
    recursive.cpp \
    scale.cpp

FORMS += \
    dialog.ui

OTHER_FILES +=

HEADERS += \
    dialog.h \
    recursive.h \
    scale.h

