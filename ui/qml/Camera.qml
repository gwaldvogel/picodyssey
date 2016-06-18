import QtQuick 2.0
import QtMultimedia 5.5

Item {
  anchors.fill: parent

  Camera {
    id: camera
    captureMode: Camera.CaptureStillImage

    imageProcessing.whiteBalanceMode: CameraImageProcessing.WhiteBalanceFlash

    exposure {
      exposureCompensation: -1.0
      exposureMode: Camera.ExposurePortrait
    }

    imageCapture {
      onImageSaved: {
        console.log(path);
        app.uploadPicture(path);
        pageStack.pop();
      }
    }
  }

  VideoOutput {
    source: camera
    anchors.fill: parent
    focus : visible
  }

  Rectangle {
    id: cameraTrigger
    width: 55
    height: 55
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.bottom: parent.bottom
    anchors.margins: 10
    radius: Screen.pixelDensity * 3

    color: "#434857"

    Image {
      id: camIcon
      anchors.centerIn: parent
      width: 40
      height: 40
      source: "qrc:/3rdparty/fontawesome/white/svg/camera.svg"
    }

    MouseArea {
      anchors.fill: parent
      onClicked: camera.imageCapture.capture();
    }
  }
}
