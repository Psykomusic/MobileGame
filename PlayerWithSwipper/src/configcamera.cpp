#include "configcamera.hpp"
#include <QFile>


using namespace std;

ConfigCamera& ConfigCamera::instance()
{
    static ConfigCamera instance;
    return instance;
}

ConfigCamera::ConfigCamera() : allConfigFile(QStringLiteral(":/ressources/cam_conf.cf")), currConfigFile(QStringLiteral(":/ressources/curr_conf.cf"))
{}
ConfigCamera::ConfigCamera(const QString& allConfigFile,const QString& currConfigFile) : allConfigFile(allConfigFile), currConfigFile(currConfigFile)
{}
ConfigCamera::~ConfigCamera()
{
    qDeleteAll(mapDiscover);
    mapDiscover.clear();
    qDeleteAll(mapDataCamera);
    mapDataCamera.clear();
}

bool ConfigCamera::isOpenableAndReadable(const QString& fileName) const
{
    QFile file(fileName);
    if ( !file.open(QIODevice::ReadOnly | QIODevice::Text) )
        {
            qDebug() << "Can't open the file" << fileName ;
            qDebug() << file.errorString();
            return false;
        }
        return true;
}

void ConfigCamera::checkInfo() const
{
    for( auto e : mapDataCamera.keys())
    {
        qDebug() << "The IP adress of the camera " << e << " is " << mapDataCamera[e]->getIpAdress() << " and the url of the stream is " << mapDataCamera[e]->getUrlStream();
    }
}

void ConfigCamera::currConfig()
{
    QFile file(currConfigFile);

    if(isOpenableAndReadable(currConfigFile))
    {
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QString lineFile;
        QTextStream in(&file);
        while (!in.atEnd())
        {

            lineFile = in.readLine();
            qDebug() << lineFile;
            if(lineFile[0] != '%')
            {
                QStringList lineInfo = lineFile.split(' ', QString::SkipEmptyParts ) ;
                Camera* camTMP(new Camera());
                camTMP->setIpAdress(lineInfo.at(0));
                camTMP->setUrlStream(lineInfo.at(1));
                camTMP->setNameCamera(lineInfo.at(2));
                camTMP->setAvailability(Camera::AVAILABLE);
                mapDataCamera[camTMP->getNameCamera()] = camTMP;
                qDebug() << "Adding" << camTMP->getNameCamera() << "to the map";
            }
        }
    }
}



void ConfigCamera::pingAndConf()
{

   QMap<QString, Camera*>::iterator it;
   qDebug() << mapDataCamera.isEmpty();
   if (!mapDataCamera.isEmpty())
   {

    for ( it = mapDataCamera.begin(); it!=mapDataCamera.end() ; it++)
    {
        QObject::connect(mapDataCamera[it.key()], SIGNAL(toDestroy(Camera*)), this, SLOT(deleteCamera(Camera*)));
        QObject::connect(mapDataCamera[it.key()], SIGNAL(toAdd(Camera*)), this, SLOT(addCamera(Camera*)));
        mapDataCamera[it.key()]->ping();

        qDebug() << "ping " << mapDataCamera[it.key()]->getIpAdress();
    }
   }

    QFile file(allConfigFile);
    if(isOpenableAndReadable(allConfigFile))
    {
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QString lineFile;
        QTextStream in(&file);
        while (!in.atEnd())
        {
             lineFile = in.readLine();
            if(lineFile[0] != '%')
            {
                QStringList lineInfo = lineFile.split(' ', QString::SkipEmptyParts ) ;
                Camera* camTMP(new Camera());
                camTMP->setIpAdress(lineInfo.at(0));
                camTMP->setUrlStream(lineInfo.at(1));
                camTMP->setNameCamera(lineInfo.at(2));
                camTMP->setAvailability(Camera::UNDEFINED);
                mapDiscover[camTMP->getNameCamera()] = camTMP;

            }

        }

    }

    for ( it = mapDiscover.begin(); it!=mapDiscover.end() ; it++)
    {
        QObject::connect(mapDiscover[it.key()], SIGNAL(toDestroy(Camera*)), this, SLOT(deleteCamera(Camera*)));
        QObject::connect(mapDiscover[it.key()], SIGNAL(toAdd(Camera*)), this, SLOT(addCamera(Camera*)));
        mapDiscover[it.key()]->ping();

        qDebug() << "ping " << mapDiscover[it.key()]->getIpAdress();
    }
}



void ConfigCamera::deleteCamera(Camera* cam)
{
    qDebug() << cam->getIpAdress() << "doesn't answer, deleting";
    delete cam;
}

void ConfigCamera::addCamera(Camera* cam)   //Cette partie du code devra être changée, la mise en place du read\write.
{
    qDebug() << cam->getIpAdress() << "answers, adding to the map";
    if(!mapDataCamera.contains(cam->getNameCamera()))
    {
        mapDataCamera[cam->getNameCamera()] = cam;
        ofstream file( currConfigFile.toStdString().c_str(), std::ios_base::app );
        string line = cam->getIpAdress().toStdString() + " " + cam->getUrlStream().toStdString() + " " +cam->getNameCamera().toStdString() + '\n';
        file << line.c_str();
    }
    qDebug() << mapDataCamera;
}

/*QMap<QString, Camera *> &ConfigCamera::CameraAvailable() const
{
    return mapDataCamera;
}*/

QString ConfigCamera::urlAvailable(int index)
{

    refreshUrlsAvalaible();
    return urlsAvailable[index];
}


QVector<QString>& ConfigCamera::getUrlsAvailable()
{
    return urlsAvailable;
}

void ConfigCamera::refreshUrlsAvalaible()
{
    if (urlsAvailable.size() != sizeConfig())
    {
        QMap<QString, Camera*>::iterator it;
         for ( it = mapDataCamera.begin(); it!=mapDataCamera.end() ; it++)
         {
             urlsAvailable.append(mapDataCamera[it.key()]->getUrlStream());
         }
    }
}

int ConfigCamera::sizeConfig() const
{
    qDebug() << "sizeConfig return" << mapDataCamera.size();
    return mapDataCamera.size();
}


bool ConfigCamera::configIsEmpty() const
{
    return mapDataCamera.isEmpty();
}

void ConfigCamera::initConfig()
{
    currConfig();
    checkInfo();
    pingAndConf();
}
