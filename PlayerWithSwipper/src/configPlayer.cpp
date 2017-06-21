#include "configPlayer.h"

ConfigPlayer::ConfigPlayer(QObject *parent)
{
  //  urls = ConfigCamera::instance().getUrlsAvailable();

}
ConfigPlayer::~ConfigPlayer()
{
}


QString ConfigPlayer::getUrl(int index)
{
    return ConfigCamera::instance().urlAvailable(index);
}

int ConfigPlayer::getSize()
{
   return ConfigCamera::instance().sizeConfig();
}
