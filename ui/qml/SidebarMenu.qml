import QtQuick 2.0
import QtQuick.Window 2.2

Rectangle {
  id: sidebarMenu
  objectName: "SidebarMenu"

  property bool isOpen: (sidebarMenu.x == 0) ? true : false
  property QtObject sidebarParent: parent

  property alias model: sidebarListView.model

  color: "#434857"

  Behavior on x {
    PropertyAnimation {
      properties: "x";
      duration: 600
      easing.type: Easing.InOutQuad;
      easing.amplitude: 2.0;
      easing.period: 1.5
    }
  }

  function toggleSidebar()
  {
    if(isOpen)
    {
      sidebarMenu.x = 0 - sidebarMenu.width;
    }
    else
    {
      sidebarMenu.x = 0;
    }
  }

  Text {
    id: centerText

    anchors.top: parent.top
    anchors.left: parent.left
    anchors.right: parent.right
    height: Screen.pixelDensity * 10

    text: qsTr("Menu")
    color: "#cccccc"
    font.pointSize: 20
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
  }

  ListView {
    id: sidebarListView

    width: sidebarMenu.width
    anchors.bottom: parent.bottom
    anchors.top: centerText.bottom

    delegate: Rectangle {
      color: (index % 2 == 0) ? "#1ca8dd" : "#1bc98e"
      width: parent.width
      height: 10 * Screen.pixelDensity

      Text {
        text: menuText + " (" + actionId + ")"
        anchors.centerIn: parent
      }
    }
  }
}
