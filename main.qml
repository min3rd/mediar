import QtQuick 2.9
import QtQuick.Window 2.2
import QtMultimedia 5.0
import Qt.labs.folderlistmodel 2.2
import QtQuick.Dialogs 1.2

Window {
    id: main_window
    visible: true
    width: 640
    height: 480
    color: "#2c2929"
    title: qsTr("Mediar")

    Audio{
        id:current_file
        autoLoad: true
        autoPlay: true
        onPlaying: {
            name_song_text.text = current_file.objectName;
        }
    }
    Item {
        id: button_panel
        x: 17
        y: 360
        width: 611
        height: 120

        Rectangle {
            id: react_loop
            x: 8
            y: 28
            width: 64
            height: 64
            color: "#000000"

            Text {
                id: text_loop
                x: 0
                y: 0
                width: 64
                height: 64
                color: "#ffffff"
                text: "Loop"
                verticalAlignment: Text.AlignVCenter
                styleColor: "#ffffff"
                font.family: "Courier"
                fontSizeMode: Text.FixedSize
                horizontalAlignment: Text.AlignHCenter
                renderType: Text.NativeRendering
                font.pointSize: 18
            }

            MouseArea {
                id: loop_button
                x: 0
                y: 0
                width: 64
                height: 64
                onClicked: {
                    receiver.click("loop");
                }
            }

        }

        Rectangle {
            id: rect_play
            x: 274
            y: 28
            width: 64
            height: 64
            color: "#000000"
            Text {
                id: text_play
                x: 0
                y: 0
                width: 64
                height: 64
                color: "#ffffff"
                text: "Play"

                font.pointSize: 18
                font.family: "Courier"
                styleColor: "#ffffff"
                fontSizeMode: Text.FixedSize
                renderType: Text.NativeRendering
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            MouseArea {
                id: play_button
                x: 0
                y: 0
                width: 64
                height: 64
                onClicked: {
                    current_file.source = receiver.click("play");
                }
            }
        }

        Rectangle {
            id: rect_pre
            x: 190
            y: 28
            width: 64
            height: 64
            color: "#000000"

            Text {
                id: text_previous
                width: 64
                height: 64
                color: "#ffffff"
                text: qsTr("Pre")
                font.family: "Courier"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 18
            }

            MouseArea {
                id: previous_button
                x: 0
                y: 0
                width: 64
                height: 64
                onClicked: {
                    current_file.source = receiver.click("previous");
                }
            }
        }

        Rectangle {
            id: rect_next
            x: 353
            y: 28
            width: 64
            height: 64
            color: "#000000"

            Text {
                id: text1
                width: 64
                height: 64
                color: "#ffffff"
                text: qsTr("Next")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 18
            }

            MouseArea {
                id: next_button
                x: 0
                y: 0
                width: 64
                height: 64
                onClicked: {
                    current_file.source = receiver.click("next");
                }
            }
        }

        Rectangle {
            id: rect_mute
            x: 539
            y: 28
            width: 64
            height: 64
            color: "#000000"
            Text {
                id: text_mute
                x: 0
                y: 0
                width: 64
                height: 64
                color: "#ffffff"
                text: "Mute"
                styleColor: "#ffffff"
                verticalAlignment: Text.AlignVCenter
                font.family: "Courier"
                fontSizeMode: Text.VerticalFit
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 18
                renderType: Text.NativeRendering
            }

            MouseArea {
                id: mute_button
                x: 0
                y: 0
                width: 64
                height: 64
                onClicked: {
                     receiver.click("mute");
                }
            }
        }




    }

    PropertyAnimation{
        id: play_anim
        target: play_background
        properties: "color"
        to: "green"
        loops: Animation.Infinite
    }
    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home
        onAccepted: {
            receiver.addFile(fileDialog.fileUrl);
        }
    }
    Rectangle{
        id: open_folder
        x: 17
        y: 16
        width: 170
        height: 29
        Text {
            id: open_text
            text: qsTr("Open")
        }
        MouseArea {
            id: mouseArea
            width: 170
            height: 29
            onClicked: {
                fileDialog.visible = true;
            }
        }

    }

    NumberAnimation{
        id: opacity_anim;
        target: play_background
        properties: "opacity"
        from: 0.3
        to: 1
        loops: Animation.Infinite
    }

    Rectangle {
        id: label_detail
        x: 17
        y: 306
        width: 611
        height: 33
        color: "#000000"

        Text {
            id: name_song_text
            x: 0
            y: 0
            width: 611
            height: 33
            color: "#ffffff"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 20
        }
    }
    Rectangle {
        id: play_background
        x: 193
        y: 16
        width: 435
        height: 284
        color: "#ffffff"

        Image {
            id: img
            width: 435
            height: 284
            source: "qrc:/qtquickplugin/images/template_image.png"
        }
    }

    Rectangle {
        id: play_list
        x: 17
        y: 51
        width: 170
        height: 249
        color: "#ffffff"

        ListView {
            id: list_song
            x: 0
            y: 0
            width: 170
            height: 235
            model: dataList
            delegate: MouseArea{
                height: 20
                width: 170
                Rectangle{
                    x:1
                    y:1
                    height: 18
                    width: 168
                    color: "black"
                }

                Text {
                    text: modelData;
                    color: "#FFFFFF"

                }
                onClicked: {
                    current_file.source = receiver.click(modelData);
                }

            }
        }
    }

}
