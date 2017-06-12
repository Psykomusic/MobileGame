/*******************************************************************************
* Copyright (c) 2014, Sergey Radionov <rsatom_gmail.com>
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*   1. Redistributions of source code must retain the above copyright notice,
*      this list of conditions and the following disclaimer.
*   2. Redistributions in binary form must reproduce the above copyright notice,
*      this list of conditions and the following disclaimer in the documentation
*      and/or other materials provided with the distribution.

* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
* OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
* OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
* WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

import QtQuick 2.1
import QtQuick.Layouts 1.0
import QmlVlc 0.1
import QtMultimedia 5.0
import QtQuick.Controls 2.1

Rectangle {
    color: 'grey';
    width : 640
    height: 480
    VlcPlayer {
        id: vlcPlayer;
        mrl: "rtsp://192.168.50.40:8557/OtonomyHdSdiStreaming/2?videoCodecType=H.264";
        function swapUrl(url) {
            vlcPlayer.mrl = url;
        }
    }
    Button {
        id : cam_HD2
        text: "SWAP to camHD1"
        onClicked: vlcPlayer.swapUrl("rtp://192.168.50.2:5370")
        anchors.bottom: parent.bottom
        anchors.left: parent.left
    }
    Button {
        id : cam_HD1
        text: "SWAP to camHD2"
        onClicked: vlcPlayer.swapUrl("rtsp://192.168.50.40:8557/OtonomyHdSdiStreaming/2?videoCodecType=H.264")
        anchors.bottom : parent.bottom
        anchors.left : cam_HD2.right
        anchors.leftMargin: 15
    }
    Button {
        id : cam_HD3
        text: "SWAP to camHD3"
        onClicked: vlcPlayer.swapUrl("rtp://192.168.50.2:5371")
        anchors.bottom : parent.bottom
        anchors.left : cam_HD1.right
        anchors.leftMargin: 15
    }
    Button {
        id : cam_HD4
        text: "SWAP to camHD4"
        onClicked: vlcPlayer.swapUrl("rtp://192.168.50.2:5372")
        anchors.bottom : parent.bottom
        anchors.left : cam_HD3.right
        anchors.leftMargin: 15
    }

   /* VlcVideoSurface {
        source: vlcPlayer;
      //  anchors.fill: parent;
     //   anchors.top: parent.top;
        anchors.topMargin: 10;/*
        anchors.left: parent.left;
        anchors.leftMargin: anchors.topMargin;
        width: parent.width / 2 - anchors.leftMargin * 2;
        height: parent.height / 2 - anchors.topMargin * 2;*/
    //}
   /* VideoOutput {
        source: vlcPlayer;
     //  anchors.top: parent.top;
        anchors.fill : parent;
       /* width: parent.width / 2;
        height: parent.height / 2;
        opacity: 0.9;*/
  //  }
    VlcVideoSurface {
        source: vlcPlayer;
        anchors.fill : parent;
       /* anchors.bottom: parent.bottom;
        anchors.bottomMargin: 10;
        anchors.right: parent.right;
        anchors.rightMargin: anchors.bottomMargin;
        width: parent.width / 2 - anchors.rightMargin * 2;
        height: parent.height / 2 - anchors.bottomMargin * 2;
        opacity: 0.9;*/
    }
    /*MouseArea {
        hoverEnabled: true
        anchors.fill: parent
        RowLayout {
            id: toolbar
            opacity: .55
            spacing: 10
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.bottomMargin: parent.containsMouse ? spacing : -height
            anchors.leftMargin: spacing * 1.5
            anchors.rightMargin: spacing * 1.5
            Behavior on anchors.bottomMargin { PropertyAnimation { duration: 250} }
            Rectangle {
                height: 24
                width: height
                radius: width * 0.25
                color: 'black'
                border.width: 1
                border.color: 'white'
                Image {
                    source: vlcPlayer.playing ? "pause.png" : "play.png"
                    anchors.centerIn: parent
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: vlcPlayer.togglePause()
                }
            }
            Rectangle {
                Layout.fillWidth: true
                height: 10
                color: 'transparent'
                border.width: 1
                border.color: 'white'
                anchors.verticalCenter: parent.verticalCenter
                Rectangle {
                    width: (parent.width - anchors.leftMargin - anchors.rightMargin) * vlcPlayer.position
                    color: 'white'
                    anchors.margins: 2
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.bottom: parent.bottom
                }
            }
        }
    }*/
}
