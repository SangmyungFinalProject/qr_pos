#-------------------------------------------------
#
# Project created by QtCreator 2017-05-03T02:40:54
#
#-------------------------------------------------

QT       += core gui network
#CONFIG   += c++14
QMAKE_CXXFLAGS += -std=gnu++14
#QMAKE_LFLAGS += -std=c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_test
TEMPLATE = app

#INCLUDEPATH += C:\opencv-build\install\include\
#               C:\ZBar\include\
#               C:\curl-7.54.0\include

#LIBS += -LC:\opencv-build\install\x86\mingw\lib \
#    -lopencv_core320.dll \
#    -lopencv_highgui320.dll \
#    -lopencv_imgcodecs320.dll \
#    -lopencv_imgproc320.dll \
#    -lopencv_features2d320.dll \
#    -lopencv_calib3d320.dll\
#    -lopencv_videoio320.dll\
#         C:\Zbar\lib\libzbar-0.lib\

INCLUDEPATH += -I/usr/include\
               -I/usr/local/include
LIBS += -L/usr/lib -lopencv_core -lopencv_highgui -lopencv_videoio -lopencv_imgproc\
        -L/usr/local/lib -lzbar
SOURCES += main.cpp\
        qt_test.cpp \
    fileio.cpp \
    qr_scan.cpp \
    send_request.cpp

HEADERS  += qt_test.h

FORMS    += qt_test.ui

RESOURCES += \
    qt_test.qrc
