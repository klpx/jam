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
                for (var i in jamClient.roster.contacts) {
                    console.log(jamClient.roster.contacts[i].name)
                }
                jamClient.ping()
            }
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
