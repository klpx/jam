import QtQuick 2.2
import QtQuick.Controls 1.1

ApplicationWindow {
    id: app
    visible: true
    width: 640
    height: 480
    title: qsTr("Jam")

    Rectangle {
        color: "black"
        clip: true
        anchors.fill: parent
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
                            text: contactList.positionViewAtEnd()
                            anchors.verticalCenter: parent.verticalCenter
                            font.bold: true
                            color: "white"
                        }
                    }
                }
            }
        }
        model: ListModel {
            ListElement {
                name: "Grey"
                colorCode: "grey"
            }

            ListElement {
                name: "Red"
                colorCode: "red"
            }

            ListElement {
                name: "Blue"
                colorCode: "blue"
            }

            ListElement {
                name: "Green"
                colorCode: "green"
            }

            ListElement {
                name: "Green"
                colorCode: "green"
            }

            ListElement {
                name: "Green"
                colorCode: "green"
            }

            ListElement {
                name: "Green"
                colorCode: "green"
            }

            ListElement {
                name: "Green"
                colorCode: "green"
            }

            ListElement {
                name: "Green"
                colorCode: "green"
            }

            ListElement {
                name: "Green"
                colorCode: "green"
            }

            ListElement {
                name: "Blue"
                colorCode: "blue"
            }


            ListElement {
                name: "Blue"
                colorCode: "blue"
            }


            ListElement {
                name: "Blue"
                colorCode: "blue"
            }


            ListElement {
                name: "Blue"
                colorCode: "blue"
            }


            ListElement {
                name: "Blue"
                colorCode: "blue"
            }

        }
    }
}
