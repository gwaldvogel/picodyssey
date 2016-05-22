import QtQuick 2.5
import QtQuick.Window 2.2

Window {
  id: mainWindow

  visible: true

  width: 414
  height: 736

  color: "#252830"

  FontLoader {
    source: "qrc:/fonts/fontawesome-webfont.ttf"
  }

  MenuBar {
    id: menuBar

    centerText: qsTr("Pic Odyssey")

    height: Screen.pixelDensity * 10
    width: parent.width
    anchors.top: mainWindow.top
    anchors.left: sidebarMenu.right

    onLeftButtonClicked: sidebarMenu.toggleSidebar();
  }

  SidebarMenu {
    id: sidebarMenu

    height: parent.height
    width: parent.width * 0.8
    x: 0 - parent.width * 0.8

    model: ListModel {
      ListElement { menuText: QT_TR_NOOP("Play"); actionId: "play" }
      ListElement { menuText: QT_TR_NOOP("Take image"); actionId: "camera" }
      ListElement { menuText: QT_TR_NOOP("Highscores"); actionId: "highscore" }
      ListElement { menuText: QT_TR_NOOP("About"); actionId: "about" }
    }
  }

  Rectangle {
    id: content

    anchors.left: sidebarMenu.right
    anchors.top: menuBar.bottom
    width: parent.width
    height: parent.height - menuBar.height

    color: "#252830"

    Image {
      source: "qrc:/res/images/dummyMap.png"
      width: parent.width
      height: parent.height - loadingBarOuter.height - lockInButton.height + 1
      fillMode: Image.PreserveAspectCrop
    }

    Rectangle {
      id: loadingBarOuter

      color: "#1ca8dd"
      anchors.bottom: lockInButton.top
      height: Screen.pixelDensity * 2
      width: parent.width

      Rectangle {
        id: loadingBarInner

        color: "#1bc98e"

        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        Behavior on width {
          PropertyAnimation {
            properties: "width"
            duration: 3000
            easing.type: Easing.Linear
          }
        }
        Component.onCompleted: {
          loadingBarInner.width = parent.width;
          timer.start();
        }
      }
    }

    Timer {
      id: timer
      interval: 3000
      repeat: true
      onTriggered: {
        if(loadingBarInner.width == 0)
          loadingBarInner.width = parent.width
        else
          loadingBarInner.width = 0;
      }
    }

    Rectangle {
      id: lockInButton

      height: Screen.pixelDensity * 10
      width: parent.width
      anchors.bottom: parent.bottom

      Text {

        anchors.centerIn: parent
        width: parent.width - 2 * parent.height
        height: parent.height

        text: "Lock in"

        color: "#51586a"

        font.pointSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
      }
    }

  }

  // mousearea to disable sidebar
  MouseArea {
    enabled: sidebarMenu.isOpen
    anchors.left: sidebarMenu.right
    anchors.top: parent.top
    anchors.right: parent.right
    anchors.bottom: parent.bottom
    onClicked: sidebarMenu.toggleSidebar()
  }
}
