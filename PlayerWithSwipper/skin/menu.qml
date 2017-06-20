import QtQuick 2.1
import QtQuick.Layouts 1.0
import QmlVlc 0.1
import QtMultimedia 5.0
import QtQuick.Controls 2.2
import "main.js" as JsEngine
import ConfigCamera 1.0

Rectangle {
    id: menu
    color: 'grey';
    width : 640
    height: 480

    ConfigCamera{
        id: configCamera;
    }

    SwipeView {
        id: view
        currentIndex: 1
        anchors.fill: parent
        function loadurl(i){
            var url = configCamera.urlAvailable(i);
            return url;
        }
        Component.onCompleted: configCamera.initConfig();
        property int length : configCamera.sizeConfig()
      //  orientation:  Qt.horizontal
        Repeater {
            id:pageRepeater
            model: view.length
            Loader {
                active: SwipeView.isCurrentItem // || SwipeView.isNextItem || SwipeView.isPreviousItem
                sourceComponent: Page_camHD {
                    Component.onCompleted: JsEngine.swipe(index)
                    Component.onDestruction: JsEngine.deswipe(index)
                    urlStream: loadurl(view.currentIndex);
                    PageIndicator {
                        height: 100
                        width: height
                        id: indicator
                        count: view.count
                        currentIndex: view.currentIndex
                        anchors.bottom: parent.bottom
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }
            }
        }
    }
}

