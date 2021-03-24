QT    += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += console c++11

TEMPLATE = app

#DEFINES += QT_DEPRECATED_WARNINGS

QMAKE_CXXFLAGS += -Wall

SOURCES += \
        Additional_classes/date.cpp \
        Additional_classes/passport.cpp \
        Additional_classes/peoplegenerator.cpp \
        Additional_classes/personalcard.cpp \
        Additional_classes/roomlocation.cpp \
        Enumerations/accesslevels.cpp \
        Logger_classes/logger.cpp \
        People_classes/admin.cpp \
        People_classes/director.cpp \
        People_classes/guest.cpp \
        People_classes/labemployee.cpp \
        People_classes/people.cpp \
        People_classes/professor.cpp \
        People_classes/student.cpp \
        People_classes/universitypeople.cpp \
        Room_classes/cabinet.cpp \
        Room_classes/classroom.cpp \
        Room_classes/conferenceroom.cpp \
        Room_classes/directorcabinet.cpp \
        Room_classes/lectureroom.cpp \
        Room_classes/livingroom.cpp \
        Room_classes/room.cpp \
        Room_classes/universityroom.cpp \
        University_classes/university.cpp \
        University_classes/universityfiller.cpp \
        UserInterface_classes/GUI/mainwindow.cpp \
        UserInterface_classes/GUI/userinterfacegui.cpp \
        UserInterface_classes/Terminal/userinterfaceterminal.cpp \
        main.cpp

HEADERS += \
    Additional_classes/date.h \
    Additional_classes/passport.h \
    Additional_classes/peoplegenerator.h \
    Additional_classes/personalcard.h \
    Additional_classes/roomlocation.h \
    Enumerations/accesslevels.h \
    Logger_classes/logger.h \
    People_classes/admin.h \
    People_classes/director.h \
    People_classes/guest.h \
    People_classes/labemployee.h \
    People_classes/people.h \
    People_classes/professor.h \
    People_classes/student.h \
    People_classes/universitypeople.h \
    Room_classes/cabinet.h \
    Room_classes/classroom.h \
    Room_classes/conferenceroom.h \
    Room_classes/directorcabinet.h \
    Room_classes/lectureroom.h \
    Room_classes/livingroom.h \
    Room_classes/room.h \
    Room_classes/universityroom.h \
    University_classes/university.h \
    University_classes/universityfiller.h \
    UserInterface_classes/GUI/mainwindow.h \
    UserInterface_classes/GUI/userinterfacegui.h \
    UserInterface_classes/Terminal/userinterfaceterminal.h

FORMS += \
    UserInterface_classes/GUI/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Images.qrc

DISTFILES +=
