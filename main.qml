import QtQuick 2.9
import QtQuick.Window 2.2
import QtMultimedia 5.0


Window {
    id: window
    visible: true
    width: 640
    height: 480
    color: "#2c2929"
    title: qsTr("Mediar")

    Audio{
        id:current_file
        source: "a.ogg"
        autoLoad: true
        autoPlay: true
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
            }
        }

        Rectangle {
            id: react_play
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
                    if(current_file.playbackState ===1){
                        current_file.play();
                    }else{
                        current_file.pause();
                    }
                    if(opacity_anim.running){
                        opacity_anim.stop();
                        text_play.text = "Play";
                        receiver.click("pause");
                    }else{
                        opacity_anim.start();
                        text_play.text = "Pause";
                        receiver.click("play");
                    }
                }
                onEntered: {

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
                    receiver.click("previous");
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
                    receiver.click("next");
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
                    if(!text_mute.text.match("mute")){
                        text_mute.text = "Ummute";
                        receiver.click("mute");
                    }else{
                        text_mute.text = "Mute";
                        receiver.click("unmute");
                    }
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
            y: 306
            width: 640
            height: 68
            color: "#b3b3b3"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 12
        }
    }
    Rectangle {
        id: play_background
        x: 193
        y: 16
        width: 435
        height: 284
        color: "#000000"
    }

    Rectangle {
        id: play_list
        x: 17
        y: 16
        width: 170
        height: 284
        color: "#000000"
    }







}
