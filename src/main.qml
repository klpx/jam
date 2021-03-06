import QtQuick 2.2
import QtQuick.Controls 1.1

ApplicationWindow {
    id: messengerWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Jam")

    Rectangle {
        color: "black"
        clip: true
        anchors.fill: parent

        Button {
            id: button1
            x: 288
            y: 262
            text: qsTr("Ping")
            onClicked: {
                jamClient.ping()
            }
        }

        Button {
            id: addContactButton
            x: 381
            y: 103
            text: qsTr("Add contact")
            onClicked: {
                jamClient.subscribe(addContactUsername.text)
            }
        }

        TextField {
            id: addContactUsername
            x: 283
            y: 72
            width: 180
            height: 25
            placeholderText: qsTr("Text Field")
        }
    }

    ListView {
        id: contactList
        width: parent.width * 0.3
        boundsBehavior: Flickable.DragOverBounds
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        keyNavigationWraps: false
        delegate: Item {
            height: 40

            Rectangle {
                width: parent.parent.width
                height: parent.height
                color: "#000"

                Rectangle {
                    anchors.fill: parent
                    anchors.bottomMargin: 1
                    color: "#343735"

                    Rectangle {
                        anchors.fill: parent
                        anchors.topMargin: 1
                        color: "#161617"

                        Rectangle {
                            color: model.online ? "green" : "red"
                            width: 10; height: 10; radius: 2
                            anchors.verticalCenter: parent.verticalCenter
                        }

                        Text {
                            anchors.verticalCenter: parent.verticalCenter
                            font.bold: true
                            color: "white"
                            text: model.name
                        }
                    }
                }
            }
        }
        model: jamClient.roster.contacts

    }
}
