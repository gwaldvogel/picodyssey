import QtQuick 2.0

Item {
  anchors.fill: parent

  Image {
    source: "file://" + app.currentPlace.image
    fillMode: Image.PreserveAspectFit
    anchors.fill: parent
  }

  MouseArea {
    anchors.fill: parent
    onClicked: pageStack.push("qrc:/qml/GamePage.qml");
  }
}
