import QtQuick 2.0
import QtQuick.Window 2.2

Item {
  id: fontAwesomeIcon
  objectName: "FontAwesomeIcon"

  property int iconSize: 25
  property string iconName: ""
  property alias iconColor: icon.color
  property bool iconBorder: false
  property string backgroundColor: ""

  Rectangle {
    id: borderRect

    color: backgroundColor
    border.color: iconColor
    radius: 5
    anchors.centerIn: parent
    width: parent.width * 0.7
    height: parent.height * 0.7

    Text {
      id: icon

      font.pointSize: iconSize * Screen.pixelDensity
      anchors.centerIn: parent
      font.family: "FontAwesome"
      text: iconName
    }
  }
}
