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

#include <QtGui/QGuiApplication>
#include <QQuickView>
#include <iostream>
#include <QmlVlc.h>
#include <QmlVlc/QmlVlcConfig.h>
#include <qmltest.h>
#include<QDebug>
#include "src/configcamera.hpp"
#include <QResource>
int main(int argc, char *argv[])
{

    //QResource::registerResource("");
    RegisterQmlVlc();
    qmlRegisterType<ConfigCamera>("ConfigCamera", 1, 0, "ConfigCamera");
    QmlVlcConfig& config = QmlVlcConfig::instance();
    ConfigCamera& cameras = ConfigCamera::instance();

    //config.setTrustedEnvironment(true);
    // config.setNetworkCacheTime(900);

  /*  cameras.currConfig();
    cameras.checkInfo();
    cameras.pingAndConf();
    if(cameras.configIsEmpty())
    {
        qDebug() << "QMap is empty, waiting for answer from cam";
        delay(10);
    }
    if(cameras.configIsEmpty())
    {
        qDebug() << "No camera";
        return 0;
    }

*/
    config.enableHardwareAcceleration(true);
    config.enableAdjustFilter( true );
    config.enableMarqueeFilter( true );
    config.enableLogoFilter( true );
    config.enableDebug( true );
    config.createLibvlcInstance();
   // qDebug() <<"//***************\\"<< config._networkCacheTime<<"//***************\\" ;
    QGuiApplication app(argc, argv);
    QQuickView view;
    view.setClearBeforeRendering( false );
    view.setMinimumSize( QSize( 640,480));
    view.show();
    view.setResizeMode( QQuickView::SizeRootObjectToView );
    view.setSource( QStringLiteral( "qrc:/skin/menu.qml" ) );

    return app.exec();
}
