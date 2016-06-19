import QtQuick 2.0
import QtQuick.Window 2.0
import QtLocation 5.6
import QtPositioning 5.3

Item {
  Map {
    id: resultMap
    plugin: Plugin {
      name: 'osm'
    }

    width: parent.width
    height: parent.height - resultText.height * 3

//    zoomLevel: resultMap.maximumZoomLevel - 3

    visibleRegion: {
      console.log(QtPositioning.rectangle(resultMarker.coordinate, actualMarker.coordinate), resultMarker.coordinate, actualMarker.coordinate)
      return QtPositioning.rectangle(resultMarker.coordinate, actualMarker.coordinate);
    }

    gesture.enabled: true

    MapPolyline {
      line.width: 3
      line.color: "#FFFF00"
      path: [
        resultMarker.coordinate,
        actualMarker.coordinate
      ]
    }

    Marker {
      id: resultMarker
//      coordinate { // carl schurz haus
//        latitude: 47.99713
//        longitude: 7.843844
//      }
      coordinate: globalInternal.markerPosition
    }

    Marker {
      id: actualMarker
      actual: true
      coordinate: app.currentPlace.geoCoordinates
    }
  }

  Text {
    id: resultText

    anchors.top: resultMap.bottom
    anchors.topMargin: Screen.pixelDensity * 5
    width: parent.width
    horizontalAlignment: Text.AlignHCenter

    font.pointSize: Screen.pixelDensity * 4
    color: "#ffffff"
    text: "Distance: " + (resultMarker.coordinate.distanceTo(actualMarker.coordinate).toFixed(2) > 2000) ? (resultMarker.coordinate.distanceTo(actualMarker.coordinate) / 1000).toFixed(2) + "km" : resultMarker.coordinate.distanceTo(actualMarker.coordinate).toFixed(2)  + "m"
    MouseArea {
      anchors.fill: parent
      onClicked: {
          pageStack.push("qrc:/qml/ImagePage.qml");
      }
    }
  }
  Component.onCompleted: {
    app.loadNewPlace();
  }
}
