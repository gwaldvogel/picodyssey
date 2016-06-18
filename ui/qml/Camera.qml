import QtQuick 2.0
import QtMultimedia 5.5

Item {
  VideoOutput {
    source: camera
    anchors.fill: parent
  }
  Camera {
    id: camera
    captureMode: Camera.CaptureStillImage

    imageCapture {
      onImageCaptured: {
        photoPreview.source = preview
        stillControls.previewAvailable = true
        cameraUI.state = "PhotoPreview"
      }
    }

    videoRecorder {
      resolution: "1920x1080"
      frameRate: 30
    }
  }
}
