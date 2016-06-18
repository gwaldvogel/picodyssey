import QtQuick 2.0
import QtQuick.Window 2.0
import QtLocation 5.6

MapQuickItem {
  id: marker
  anchorPoint.x: image.width / 2
  anchorPoint.y: image.height * 0.9

  property bool actual: false

  sourceItem: Item {
    width: Screen.pixelDensity * 12
    height: Screen.pixelDensity * 12

    Image {
      id: image
      source: marker.actual ? "qrc:/res/images/map-marker-result.svg" : "qrc:/res/images/map-marker.svg"
      width: Screen.pixelDensity * 12
      height: Screen.pixelDensity * 12
      anchors.centerIn: parent
    }
  }
}
