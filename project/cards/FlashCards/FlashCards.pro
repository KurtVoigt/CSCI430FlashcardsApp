#-------------------------------------------------
#
# Project created by QtCreator 2020-11-26T13:54:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FlashCards
TEMPLATE = app
LIBS += -lsqlite3
QMAKE_CXXFLAGS += -std=c++11


SOURCES += main.cpp\
        flashcards.cpp \
    ../../src/deck.cpp \
    ../../src/card.cpp \
    newDeckFrame.cpp \
    startFrame.cpp \
    loadDeckFrame.cpp \
    questionFrame.cpp \
    answerFrame.cpp \
    editDeckFrame.cpp

HEADERS  += flashcards.h \
    ../../src/card.h \
    ../../src/deck.h \
    newDeckFrame.h \
    startFrame.h \
    loadDeckFrame.h \
    questionFrame.h \
    answerFrame.h \
    editDeckFrame.h

FORMS    += flashcards.ui \
    newDeckFrame.ui \
    startFrame.ui \
    loadDeckFrame.ui \
    questionFrame.ui \
    answerFrame.ui \
    editDeckFrame.ui
