import QtQuick 2.5
import QtQuick.Window 2.0

Rectangle {
  id: textInputField
  objectName: "TextInputField"

  property string placeholder: ""
  property bool password: false
  property alias text: textInput.text

  width: (parent.width * 0.8 <= Screen.pixelDensity * 100) ? parent.width * 0.8 : Screen.pixelDensity * 100
  height: Screen.pixelDensity * 15
  anchors.horizontalCenter: parent.horizontalCenter
  radius: Screen.pixelDensity * 3

  color: "#434857"

  TextInput {
    id: textInput

    anchors.centerIn: parent
    width: parent.width * 0.8
    height: parent.height * 0.8
    horizontalAlignment: TextInput.AlignHCenter
    verticalAlignment: TextInput.AlignVCenter

    text: textInputField.placeholder
    echoMode: textInputField.password ? TextInput.Password : TextInput.Normal

    onFocusChanged: {
      if(textInput.focus && textInput.text == textInputField.placeholder)
      {
        textInput.text = ""
      }
    }

    onEditingFinished: {
      if(textInput.text == "")
      {
        textInput.text = textInputField.placeholder
      }
    }

    color: "#ffffff"
  }
}
