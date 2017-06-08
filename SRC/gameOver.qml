import QtQuick 2.0
import QtQuick.Controls 1.5
Rectangle {
    visible: true
    color: "grey"
    width: main.oGame.getWidth()
    height: main.oGame.getHeight()
    Image {
        source :"../shared/pics/gameOver.jpeg"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        width: main.oGame.convert(1080)
        height: main.oGame.convert(1920)
        Button {
            id : replayButton
            text : qsTr("Replay !")
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            width: main.oGame.convert(450)
            height: main.oGame.convert(150)
            onClicked: main.oGame.gotoScene()
        }
        Button {
            anchors.horizontalCenter: parent.horizontalCenter
            //anchors.verticalCenter: parent.verticalCenter
            //anchors.verticalCenterOffset: 50
            anchors.top: replayButton.bottom
            anchors.topMargin: 50
            width: main.oGame.convert(450)
            height: main.oGame.convert(150)
            text: qsTr("Go Back to Menu")
            onClicked: main.oGame.gotoMenu()
        }
    }
}

