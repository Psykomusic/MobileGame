import QtQuick 2.1
import QtQuick.Layouts 1.0
import QmlVlc 0.1
import QtMultimedia 5.0
import QtQuick.Controls 2.2

Rectangle {
    id: menu
    color: 'grey';
    width : 1920
    height: 1080

    SwipeView {
        id: view
        currentIndex: index
        anchors.fill: parent
        orientation:  Qt.Vertical
        Repeater {
            id:pageRepeater
            model: 5
            Loader {
                active: SwipeView.isCurrentItem || SwipeView.isNextItem || SwipeView.isPreviousItem
                sourceComponent: Page_camHD {
                    Component.onCompleted: console.log("created:", index)
                    Component.onDestruction: console.log("destroyed:", index)
                    index : view.currentIndex;
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

