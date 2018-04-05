#-------------------------------------------------
#
# Project created by QtCreator 2016-04-25T16:24:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = SVCH_AutoEmis
TEMPLATE = app

 QMAKE_CXXFLAGS += -fopenmp -mavx -fabi-version=0 -ffast-math
 QMAKE_LFLAGS += -fopenmp

 QMAKE_CXXFLAGS_RELEASE *= -O3


QMAKE_LIBS+=-static -lgomp -lpthread

QMAKE_LFLAGS +=  -static -static-libgcc


SOURCES += main.cpp\
    qcustomplot.cpp \
    bodycls.cpp \
    settings.cpp \
    MainWin.cpp


HEADERS  += \
    qcustomplot.h \
    bodycls.h \
    settings.h \
    MainWin.h \
    physconst.h


FORMS    += \
    settings.ui \
    MainWin.ui
