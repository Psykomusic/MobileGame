#include "pinger.hpp"

Pinger::Pinger()
{

}

Pinger::Pinger(QString ip) : ipAdress(ip)
{
}

Pinger::~Pinger()
{
    delete pingProcess;
}

void Pinger::run()
{

    pingProcess = new QProcess();
    qRegisterMetaType<QProcess::ExitStatus>("QProcess::ExitStatus");
    QObject::connect(pingProcess, SIGNAL(finished(int, QProcess::ExitStatus)), this,SLOT(Messaging(int, QProcess::ExitStatus)));
    pingProcess->start("ping", QStringList() << "-c" << "1" << ipAdress);

    qDebug() << "Pinging" << ipAdress;
    pingProcess->waitForFinished(-1);
}

void Pinger::Messaging(const int& exitCode, const QProcess::ExitStatus& exitStatut)
{
    if (exitCode == 0 && exitStatut == 0)
        {
           emit resultReady(0);
        }
        else
        {
            emit resultReady(1);
        }
}

void Pinger::setIp(const QString& ip)
{
    ipAdress = ip;
}

