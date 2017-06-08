import QtQuick 2.0
import QtQuick.Controls 1.5

Rectangle {
    visible : true
    color : "grey"
    width: main.oGame.getWidth()
    height: main.oGame.getHeight()
    Image {
        source : "../shared/pics/background.jpg"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        width: main.oGame.convert(1080)
        height: main.oGame.convert(1920)
        Button {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            width : main.oGame.convert(450)
            height: main.oGame.convert(150)
            text : qsTr("Play !")
            onClicked:main.oGame.gotoScene()

        }
    }
}

