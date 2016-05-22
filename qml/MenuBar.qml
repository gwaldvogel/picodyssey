import QtQuick 2.0

Rectangle {
  id: menuBar
  objectName: "MenuBar"

  property string centerText: ""

  color: "#252830"

  signal leftButtonClicked()
  signal rightButtonClicked()

  Rectangle {
    id: leftButton

    height: parent.height
    width: height
    anchors.left: parent.left
    anchors.top: parent.top

    color: "#252830"

    FontAwesomeIcon {
      anchors.fill: parent
      iconSize: 5
      iconName: "\uf0c9"
      iconColor: "#51586a"
      iconBorder: true
      backgroundColor: "#252830"
    }

    MouseArea {
      anchors.fill: parent
      onClicked: menuBar.leftButtonClicked()
    }
  }

  Text {
    id: centerText

    anchors.centerIn: parent
    width: parent.width - 2 * parent.height
    height: parent.height

    text: menuBar.centerText

    color: "#51586a"

    font.pointSize: 20
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
  }

  Rectangle {
    id: rightButton

    height: parent.height
    width: height
    anchors.right: parent.right
    anchors.top: parent.top

    color: "#252830"

    MouseArea {
      anchors.fill: parent
      onClicked: menuBar.rightButtonClicked()
    }
  }
}
