import QtQuick 2.0
import QtQuick.Window 2.0
import QtLocation 5.3

Item {
  id: gamePage
  objectName: "GamePage"

  Map {
    id: map
    plugin: Plugin {
      name: 'osm'
    }

    width: parent.width
    height: parent.height - loadingBarOuter.height - lockInButton.height + 1

    zoomLevel: map.maximumZoomLevel - 3

    center { // carl schurz haus
      latitude: 47.99713
      longitude: 7.843844
    }

    gesture.enabled: true

    Marker {
      id: marker
      coordinate { // carl schurz haus
        latitude: 47.99713
        longitude: 7.843844
      }
      visible: false
    }
    MouseArea {
      anchors.fill: parent
      onClicked: {
        marker.coordinate = map.toCoordinate(Qt.point(mouse.x, mouse.y), true);
        marker.visible = true
      }
    }
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
      width: 0
      Behavior on width {
        PropertyAnimation {
          properties: "width"
          duration: 30000
          easing.type: Easing.Linear
        }
      }
    }
  }

  Component.onCompleted: {
    loadingBarInner.width = parent.width;
    timer.start();
  }

  Timer {
    id: timer
    interval: 30000
    repeat: false
    onTriggered: {
      console.log("time is over");
      pageStack.push("qrc:/qml/ResultPage.qml");
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

    MouseArea {
      anchors.fill: parent
      onClicked: {
        if(marker.visible)
        {
          console.log("locked in");
          pageStack.push("qrc:/qml/ResultPage.qml");
          timer.stop();
        }
      }
    }
  }
}
