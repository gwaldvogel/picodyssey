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

  signal itemClicked(string actionId);

  Text {
    id: centerText

    anchors.top: parent.top
    anchors.left: parent.left
    anchors.right: parent.right
    height: Screen.pixelDensity * 10

    text: qsTr("Menu")
    color: "#1ca8dd"
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
      color: (index % 2 == 0) ? "#494E5E" : "#4E5261"
      width: parent.width
      height: 10 * Screen.pixelDensity

      Text {
        text: menuText
        anchors.centerIn: parent
        color: "#cccccc"
        font.pointSize: Screen.pixelDensity * 3
      }

      MouseArea {
        anchors.fill: parent
        onClicked: {
          itemClicked(actionId);
          console.log(actionId);
        }
      }
    }
  }
  Image {
    source: "file://" + app.currentPlace.image
  }
}
