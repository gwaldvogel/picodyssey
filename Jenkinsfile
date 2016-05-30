stage "Start Android Build"
node("linux&&android_armv7") {
    deleteDir()
    git url: 'git@github.com:gwaldvogel/picodyssey.git'
    stage "Build Android"
    sh "mkdir build"
    dir("build") {
        sh "qmake ../picodyssey.pro -r -spec android-g++"
        sh "make"
        sh "make INSTALL_ROOT=./android-build/ install"
        sh "/opt/qt/5.6/android_armv7/bin/androiddeployqt --input android-libpicodyssey.so-deployment-settings.json --output android-build --deployment bundled --android-platform android-23 --jdk /usr/lib/jvm/java-8-oracle"
    }
    stage "Archive APKs"
    sh "cp build/android-build/bin/QtApp-debug.apk ./picodyssey_android_armv7_${env.BUILD_NUMBER}.apk"
    archive "picodyssey_android_armv7_${env.BUILD_NUMBER}.apk"
}
stage "Start iOS build Build"
node("macos&&ios") {
    deleteDir()
    git url: 'git@github.com:gwaldvogel/picodyssey.git'
    stage "Build iOS"
    sh "mkdir build"
    dir("build") {
        sh "/opt/qt/5.6/ios/bin/qmake ../picodyssey.pro -r -spec macx-ios-clang CONFIG+=iphoneos CONFIG+=device"
        sh "xcodebuild build -scheme picodyssey  -sdk iphoneos  -configuration Debug  -destination \"generic/platform=iOS\" -destination-timeout 1 CODE_SIGN_IDENTITY=\"\" CODE_SIGNING_REQUIRED=NO"
    }
}
stage "Start Linux Build"
node("linux") {
    deleteDir()
    git url: 'git@github.com:gwaldvogel/picodyssey.git'
    stage "Build Linux"
    sh "mkdir build"
    dir("build") {
        sh "/opt/qt/5.6/gcc_64/bin/qmake ../picodyssey.pro -r -spec linux-g++"
        sh "make"
    }
}
stage "Start Mac Build"
node("macos") {
    deleteDir()
    git url: 'git@github.com:gwaldvogel/picodyssey.git'
    stage "Build Mac"
    sh "mkdir build"
    dir("build") {
        sh "/opt/qt/5.6/clang_64/bin/qmake ../picodyssey.pro -r -spec macx-clang"
        sh "make"
    }
}
