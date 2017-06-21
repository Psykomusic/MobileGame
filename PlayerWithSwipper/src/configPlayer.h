#pragma once

#include "QmlVlcPlayer.h"
#include "configcamera.hpp"

class ConfigPlayer
    : public QObject
{
    Q_OBJECT

public:
    explicit ConfigPlayer( QObject* parent = 0 );
    ~ConfigPlayer();
    Q_INVOKABLE QString getUrl(int) ;
    Q_INVOKABLE int getSize() ;
private:
   // QVector<QString> urls;
};
