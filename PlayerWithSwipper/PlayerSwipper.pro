QT += qml quick multimedia

include(deps/QmlVlc/QmlVlc.pri)

INCLUDEPATH += deps

SOURCES += main.cpp \
    src/additional_functions.cpp \
    src/camera.cpp \
    src/configcamera.cpp \
    src/pinger.cpp \
    src/configPlayer.cpp

RESOURCES += main.qrc

OTHER_FILES += \
    skin/Page_camHD.qml\
    skin/basic_2.qml \
    skin/pause.png \
    skin/play.png

CONFIG += c++11

macx {
    LIBS += -L/Applications/VLC.app/Contents/MacOS/lib
}

android {
    LIBS += -L$$PWD/android/libs/armeabi-v7a -lvlcjni

    ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
}

DISTFILES += \
    skin/menu.qml \
    skin/Page_camHD.qml \
    skin/main.js \
    Ressources/cam_conf.cf \
    Ressources/curr_conf.cf

HEADERS += \
    src/additional_functions.hpp \
    src/camera.hpp \
    src/configcamera.hpp \
    src/pinger.hpp \
    src/configPlayer.h
