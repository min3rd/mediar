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
    color: "#403636"
    title: qsTr("Mediar")

    Audio{
        id:current_file
        autoLoad: true
        autoPlay: true
    }
    Item {
        id: button_panel
        x: 17
        y: 376
        width: 611
        height: 104

        Rectangle {
            id: rect_loop
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

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home
        onAccepted: {
            receiver.addFile(fileDialog.fileUrl);
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
        y: 354
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
        y: 53
        width: 435
        height: 284
        color: "#ffffff"

        Image {
            id: img
            width: 435
            height: 284
            //source: "qrc:/qtquickplugin/images/template_image.png"
        }
    }

    Rectangle {
        id: play_list
        x: 17
        y: 53
        width: 170
        height: 284
        color: "#ffffff"

        ListView {
            id: list_song
            x: 0
            y: 0
            width: 170
            height: 284
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

                    text: name;
                    color: "#FFFFFF"

                }
                onClicked: {
                    current_file.source = filePath;
                }

            }
        }
    }

    MouseArea {
        id: vietname_Mouse
        x: 528
        y: 16
        width: 100
        height: 24


        Rectangle {
            id: rectangle
            width: 100
            height: 24
            color: "#ffffff"
        }
        Text {
            id: text2
            x: 18
            y: 5
            text: qsTr("Vietnamese")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.bold: false
            fontSizeMode: Text.HorizontalFit
            renderType: Text.NativeRendering
            styleColor: "#000000"
            font.pixelSize: 12
        }
        onClicked: {
            receiver.click('vietnamese');
        }
    }

    MouseArea {
        id: english_Mouse
        x: 416
        y: 16
        width: 100
        height: 24
        Rectangle {
            id: rectangle1
            width: 100
            height: 24
            color: "#ffffff"
        }

        Text {
            id: text3
            x: 32
            y: 5
            text: qsTr("English")
            verticalAlignment: Text.AlignVCenter
            renderType: Text.NativeRendering
            font.bold: false
            font.pixelSize: 12
            fontSizeMode: Text.HorizontalFit
            styleColor: "#000000"
            horizontalAlignment: Text.AlignHCenter
        }
        onClicked: {
            receiver.click('english');
        }
    }

}
