QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    book.cpp \
    books_add.cpp \
    books_add_aut.cpp \
    books_add_cat.cpp \
    books_add_genre.cpp \
    bookswindow.cpp \
    concertswindow.cpp \
    main.cpp \
    mainwindow.cpp \
    museumswindow.cpp \
    theatreswindow.cpp

HEADERS += \
    book.h \
    books_add.h \
    books_add_aut.h \
    books_add_cat.h \
    books_add_genre.h \
    bookswindow.h \
    concertswindow.h \
    mainwindow.h \
    museumswindow.h \
    theatreswindow.h

FORMS += \
    books_add.ui \
    books_add_aut.ui \
    books_add_cat.ui \
    books_add_genre.ui \
    bookswindow.ui \
    concertswindow.ui \
    mainwindow.ui \
    museumswindow.ui \
    theatreswindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
