import QtQuick 2.0
import QtQuick.Window 2.0

Image {
  id: loginPage
  objectName: "LoginPage"

  source: "qrc:/res/images/LoginScreen.png"

  Column {
    anchors.centerIn: parent
    width: parent.width
    height: (3 * Screen.pixelDensity * 15) + Screen.pixelDensity * 2

    TextInputField {
      id: username

      placeholder: "Username"
    }

    // Abstandshalter
    Item {
      width: parent.width
      height: Screen.pixelDensity * 2
    }

    TextInputField {
      id: password

      password: true
      placeholder: "Password"
    }

    // Abstandshalter
    Item {
      width: parent.width
      height: Screen.pixelDensity * 2
    }

    Rectangle {
      id: loginButton
      width: parent.width * 0.4 - Screen.pixelDensity
      height: Screen.pixelDensity * 15
      anchors.horizontalCenter: parent.horizontalCenter
      radius: Screen.pixelDensity * 3

      color: "#434857"

      Text {
        width: parent.width * 0.8
        height: Screen.pixelDensity
        anchors.centerIn: parent

        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter

        text: "Login"
        color: "#ffffff"
      }

      MouseArea {
        anchors.fill: parent
        onClicked: {
//          if(username.text == "admin" && password.text == "admin")
          {
            app.loggedIn = true;
            pageStack.pop();
            console.log("login worked!");
          }
        }
      }
    }
  }
}
