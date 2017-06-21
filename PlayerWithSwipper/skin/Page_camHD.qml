import QtQuick 2.0
import QtQuick.Controls 2.1
import QmlVlc 0.1
import QtMultimedia 5.0

Rectangle {
    //id: page_camHD1
    color: 'grey';
    width : menu.width
    height: menu.height

    property var urlStream

     VlcPlayer{
        id: vlcPlayer;
        //mrl: "rtsp://192.168.50.40:8557/OtonomyHdSdiStreaming/2?videoCodecType=H.264";
         mrl: urlStream
        function refresh() {
            vlcPlayer.mrl = urlStream;
            console.log("refresh:", vlcPlayer.mrl)
        }
    }
    VlcVideoSurface {
        //  transform: Rotation{origin.x :width/2; origin.y : height/2; angle: 90}
        source: vlcPlayer;
        width : parent.width
        height: parent.height
        anchors.top : parent.top
        anchors.fill : parent;
        Rectangle {
            height: 100
            width: height
            radius: width * 0.25
            color: 'black'
            border.width: 1
            border.color: 'white'
            anchors.bottom: parent.bottom
            anchors.bottomMargin: parent.height/5
            anchors.horizontalCenter: parent.horizontalCenter
            Image {
                source: "play.png"
                anchors.centerIn: parent
            }
            MouseArea {
                anchors.fill: parent
                onClicked: vlcPlayer.refresh()
         //       onClicked: test.refresh()
            }
        }
    }
}
