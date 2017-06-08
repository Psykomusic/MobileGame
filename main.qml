import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import "Game.js" as Game

Window {
    visible: true
    id : main
    color : "#224422"
    property var oGame
    contentOrientation : Qt.PortraitOrientation
    function initApplication() {
        this.oGame = Game;
        this.oGame.start(1080, 1920);
    }
    Component.onCompleted: initApplication()
    StackView {
        id : stack
        width: parent.width
        height:parent.height

    }
    function popPage() {
        stack.pop();
    }
    function launchPage(sView){
        return stack.push('qrc:/'+sView+'.qml');
    }

}

