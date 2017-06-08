import QtQuick 2.0
import QtQuick.Controls 1.5
Rectangle {
    visible : true
    color : "grey"
    width: main.oGame.getWidth()
    height : main.oGame.getHeight()

    Button {
        width: main.oGame.convert(450)
        height: main.oGame.convert(150)
        text : qsTr("go GameOver!")
        onClicked: main.oGame.gotoGameover()
    }
}

