TEMPLATE = app

QT += qml quick svg
CONFIG += c++11

SOURCES += src/main.cpp \
    src/bl/cloudconnection/CloudConnection.cpp \
    src/bl/cloudconnection/CloudConfig.cpp \
    src/bl/MainApplication.cpp

INCLUDEPATH += src/bl \
               src/bl/cloudconnection

RESOURCES += ui/qml.qrc \
            3rdparty/3rdpartyresources.qrc

ios {
    QMAKE_INFO_PLIST = ios/Info.plist
    ios_icon.files = $$files($$PWD/ios/icons/Icon*.png)
    QMAKE_BUNDLE_DATA += ios_icon
    app_launch_images.files = $$files($$PWD/ios/splashscreens/LaunchImage*.png)
# $$PWD/ios/Launch.xib
    QMAKE_BUNDLE_DATA += app_launch_images
}

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

HEADERS += \
    src/bl/cloudconnection/CloudConnection.h \
    src/bl/cloudconnection/CloudConfig.h \
    src/bl/MainApplication.h

# thirdparty
include(3rdparty/o2/src/src.pri)
