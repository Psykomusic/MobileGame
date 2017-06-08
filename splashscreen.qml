import QtQuick 2.0

Rectangle {

    visible : true
    color: "grey"
    width: main.oGame.getWidth()
    height: main.oGame.getHeight()
    Image {
        width: main.oGame.convert(1080)
        height: main.oGame.getHeight(1920)
        source : "../shared/pics/mountainSky.png"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        smooth : true
    }
    Timer {
        id:timerSplashscreen
        interval : 4000;
        running:  true
        repeat : false
        onTriggered: main.oGame.gotoMenu();
    }
}
