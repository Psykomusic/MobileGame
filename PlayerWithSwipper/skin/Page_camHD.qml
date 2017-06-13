import QtQuick 2.0
import QtQuick.Controls 2.1
import QmlVlc 0.1
import QtMultimedia 5.0

Rectangle {
    //id: page_camHD1
    color: 'grey';
    width : menu.width
    height: menu.height

    property int index
    property var url : [
    "rtsp://192.168.50.40:8557/OtonomyHdSdiStreaming/2?videoCodecType=H.264",
    "rtp://192.168.50.2:5368",
    "rtp://192.168.50.2:5370",
    "rtp://239.1.172.206:53666",
    "rtp://239.1.172.207:53668",
]

    VlcPlayer {
        id: vlcPlayer;
       //mrl: "rtsp://192.168.50.40:8557/OtonomyHdSdiStreaming/2?videoCodecType=H.264";
        mrl: url[index]
        function refresh() {
            vlcPlayer.mrl = url[index];
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
            }
        }
    }
  /*  Button {
        id : refresh_button
        text: "Refresh"
        onClicked: vlcPlayer.refresh()
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }*/


}
