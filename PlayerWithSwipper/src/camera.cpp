#include "camera.hpp"

Camera::Camera()
{
    pingCamera = new Pinger();
}



Camera::Camera(const QString& IP, const QString& URL, const QString& Name): ipAdress(IP), urlStream(URL), nameCamera(Name)
{
    pingCamera = new Pinger(ipAdress);
}

Camera::Camera(const QString& IP, const QString& URL,const QString& Name, const CameraStatus& available): ipAdress(IP), urlStream(URL), nameCamera(Name), enum_isAvailable(available)
{
    pingCamera = new Pinger(ipAdress);

}

Camera::~Camera()
{
    delete pingCamera;
}

Camera::CameraStatus Camera::Availability() const
{
    return enum_isAvailable;
}

void Camera::setAvailability(const Camera::CameraStatus& b)
{
    enum_isAvailable = b;
}


void Camera::setIpAdress(const QString& ip)
{
        ipAdress = ip;
        pingCamera->setIp(ip);
}

QString Camera::getIpAdress() const
{
    return ipAdress;
}

void Camera::setUrlStream(const QString& url)
{
    urlStream = url;
}

QString Camera::getUrlStream() const
{
    return urlStream;
}


void Camera::setNameCamera(const QString& name)
{
    nameCamera = name;
}

QString Camera::getNameCamera() const
{
    return nameCamera;
}


void Camera::ping() const
{

    QObject::connect(pingCamera, SIGNAL(resultReady(int)), this, SLOT(pingRequest(int)));
    QObject::connect(pingCamera, &Pinger::finished, pingCamera, &QObject::deleteLater);
    qDebug() << "in ping" << ipAdress;
    pingCamera->start();
}


void Camera::pingRequest(int exitCode)
{
   qDebug() << "Ping Request responding";
   if(exitCode == 0 && Availability() == Camera::UNDEFINED) // Je suis ici dans le cas d'une nouvelle camera à tester, si elle répond oui je l'ajoute à la map
   {
       emit toAdd(this);
   }
   else if (exitCode == 1 && Availability() == Camera::AVAILABLE) //je suis ici dans le cas d'une camera
   {
       setAvailability(Camera::NOTAVAILABLE);

   }
   else if (exitCode == 1 && Availability() == Camera::UNDEFINED)
   {
       emit toDestroy(this);
   }
}




