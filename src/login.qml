import QtQuick 2.2
import QtQuick.Controls 1.1

ApplicationWindow {
    id: loginWindow
    visible: true
    width: 248
    height: 350
    title: qsTr("Jam")

    Loader {
        id: loader
        anchors.fill: parent
    }

    Rectangle {
        color: "black"
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        clip: true
        anchors.fill: parent

        Text {
            id: title
            x: 84
            y: 62
            color: "#ffffff"
            text: "Jam"
            font.family: "Tahoma"
            font.pixelSize: 43
        }

        TextField {
            id: usernameInput
            x: 24
            y: 201
            width: 200
            height: 25
            text: "jam@xmpp.ru"
            placeholderText: qsTr("your address")
        }

        TextField {
            id: passwordInput
            x: 24
            y: 232
            width: 200
            height: 25
            placeholderText: qsTr("your password")
        }

        Button {
            id: signInButton
            x: 139
            y: 263
            text: qsTr("Sign in")
            onClicked: {
                jamClient.connect(usernameInput.getText(), passwordInput.getText())
                loginWindow.close()
                loader.source="main.qml"
            }
        }
    }
}
