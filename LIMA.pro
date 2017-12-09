#-------------------------------------------------#
#                                                 #
# Project Created by Bhurinuth Wongsrisakul       #
#                    ID# 58090030                 #
#                                                 #
# LIMA - LIbrary Management and Administration    #
#                                                 #
# Project created by Poom 2016-04-05T13:31:08     #
# Project updated by Poom 2016-04-24T16:36:32     #
#                                                 #
#-------------------------------------------------#

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LIMA
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp \
    userarea.cpp \
    registration.cpp \
    admin.cpp \
    dataedit.cpp \
    bookregis.cpp \
    message.cpp

HEADERS  += login.h \
    userarea.h \
    registration.h \
    admin.h \
    dataedit.h \
    bookregis.h \
    message.h

FORMS    += login.ui \
    userarea.ui \
    registration.ui \
    admin.ui \
    dataedit.ui \
    bookregis.ui

RC_FILE = icon.rc
