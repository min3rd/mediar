import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    color: "#fdfdfd"
    title: qsTr("Mediar")

    MouseArea {
        id: play_button
        x: 270
        y: 380
        width: 64
        height: 64

        Rectangle {
            id: mesh
            x: 0
            y: 0
            width: 64
            height: 64
            color: "#000000"
        }
        onClicked: {
            receiver.click("play");
        }
    }

    MouseArea {
        id: next_button
        x: 370
        y: 380
        width: 64
        height: 64
        Rectangle {
            id: mesh1
            x: 0
            y: 0
            width: 64
            height: 64
            color: "#000000"
        }
        onClicked: {
            receiver.click("next");
        }
    }

    MouseArea {
        id: previous_button
        x: 171
        y: 380
        width: 64
        height: 64
        Rectangle {
            id: mesh2
            x: 0
            y: 0
            width: 64
            height: 64
            color: "#000000"
        }
        onClicked: {
            receiver.click("previous");
        }
    }

    Text {
        id: name_song_text
        x: 16
        y: 306
        width: 606
        height: 68
        text: qsTr("")
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 12
    }

    ListView {
        id: listView
        x: 16
        y: 17
        width: 219
        height: 249
        highlightRangeMode: ListView.ApplyRange
        delegate: Item {
            x: 5
            width: 80
            height: 40
            Row {
                id: row1
                Rectangle {
                    width: 40
                    height: 40
                    color: colorCode
                }

                Text {
                    text: name
                    anchors.verticalCenter: parent.verticalCenter
                    font.bold: true
                }
                spacing: 10
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
        }
    }
}
