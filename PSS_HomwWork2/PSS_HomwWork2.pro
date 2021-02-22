TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Additional_classes/date.cpp \
        Additional_classes/passport.cpp \
        Additional_classes/personalcard.cpp \
        Additional_classes/roomlocation.cpp \
        People_classes/admins.cpp \
        People_classes/director.cpp \
        People_classes/labemployees.cpp \
        People_classes/people.cpp \
        People_classes/professor.cpp \
        People_classes/student.cpp \
        People_classes/universitypeople.cpp \
        Room_classes/cabinet.cpp \
        Room_classes/conferenceroom.cpp \
        Room_classes/directorcabinet.cpp \
        Room_classes/lectureroom.cpp \
        Room_classes/livingroom.cpp \
        Room_classes/room.cpp \
        Room_classes/universityroom.cpp \
        University_class/university.cpp \
        main.cpp

HEADERS += \
    Additional_classes/date.h \
    Additional_classes/passport.h \
    Additional_classes/personalcard.h \
    Additional_classes/roomlocation.h \
    Enumerations/accesslevels.h \
    People_classes/admins.h \
    People_classes/director.h \
    People_classes/labemployees.h \
    People_classes/people.h \
    People_classes/professor.h \
    People_classes/student.h \
    People_classes/universitypeople.h \
    Room_classes/cabinet.h \
    Room_classes/conferenceroom.h \
    Room_classes/directorcabinet.h \
    Room_classes/lectureroom.h \
    Room_classes/livingroom.h \
    Room_classes/room.h \
    Room_classes/universityroom.h \
    University_class/university.h