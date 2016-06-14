import QtQuick 2.0
import QtQuick.Window 2.2

Item {
  id: fontAwesomeIcon
  objectName: "FontAwesomeIcon"

  property int iconSize: 25
  property string iconName: ""
  property bool iconBorder: false
  property bool darkMode: false
  property string backgroundColor: ""
  property double iconOpacity: 0.8

  Rectangle {
    id: borderRect

    color: backgroundColor
    border.color: fontAwesomeIcon.darkMode ? "#000000" : "#ffffff"
    radius: 5
    anchors.centerIn: parent
    width: parent.width * 0.7
    height: parent.height * 0.7
    opacity: fontAwesomeIcon.iconOpacity

    Image {
      id: icon

      anchors.centerIn: parent
      anchors.fill: parent
      anchors.margins: parent.width * 0.1
      source: fontAwesomeIcon.darkMode ? "qrc:/3rdparty/fontawesome/black/svg/" + iconName + ".svg" : "qrc:/3rdparty/fontawesome/white/svg/" + iconName + ".svg"
      opacity: fontAwesomeIcon.iconOpacity
    }
  }
}
