# http://doc.qt.io/qt-5/qmake-variable-reference.html

QT += core widgets gui
DEFINES += QT_WIDGETS_LIB
INCLUDEPATH += .

HEADERS += paint.h \
           canvas.h \
           circle.h
SOURCES += paint.cpp \
           canvas.cpp \
           circle.cpp \
           main.cpp
