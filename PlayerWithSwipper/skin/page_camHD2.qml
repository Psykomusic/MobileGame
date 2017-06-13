import QtQuick 2.0
import QtQuick.Controls 2.1
import QmlVlc 0.1
import QtMultimedia 5.0

Rectangle {
    id: page_camHD2
    color: 'grey';
    width : menu.width
    height: menu.height
    VlcPlayer {
        id: vlcPlayer;
        mrl: "rtp://192.168.50.2:5368";
        function refresh() {
            vlcPlayer.mrl = mrl;
        }
    }
    VlcVideoSurface {
        source: vlcPlayer;
        anchors.fill : parent;
        Button {
            id : refresh_button
            text: "Refresh"
            onClicked: vlcPlayer.refresh()
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
