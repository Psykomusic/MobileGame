#ifndef PINGER
#define PINGER

//!
//!\file ping.hpp
//!\brief Classe ping.hpp, classe fille de QThread qui lance un ping dans un autre thread.
//!\author PITAUD Antoine
//!\version 0.1
//!\date 09 Mai 2017
//!
//!\details Classe pinger.hpp, contient l'adresse IP à tester, lance un ping pour tester la présence sur le réseau.
//! Si l'adresse répond envoie le signal "OK", sinon "OUT".
//!
//!

#include "QProcess"
#include "QTimer"
#include "QDebug"
#include "QThread"
#include "QObject"
#include "fstream"
#include "QMap"
//#include "camera.hpp"



//! \class Pinger
//! \brief Classe file de QThread
//! \details Cette classe permet de lancer un ping via un QThread, utilise le signal resultReady pour envoie "OK" ou "OUT".
//!
class Pinger : public QThread
{
    Q_OBJECT
public:
    //! \fn Pinger()
    //! \brief Constructeur
    //! \details Constructeur vide de la classe.
    Pinger();

    //! \fn Pinger(QString)
    //! \brief Constructeur
    //! \details Constructeur et initialisation du QString ipAdress.
    Pinger(QString);

    //! \fn ~Pinger()
    //! \brief Destructeur
    //! \details Destructeur et libération de la mémoire.
    ~Pinger();

    //! \fn setIp(const QString&)
    //! Accesseur en écriture de l'attribut ipAdress.
    void setIp(const QString&);

signals:
    //! \fn resultReady()
    //! \brief Méthode qui transmet l'information du ping au thread principal.
    //! \details Emet un signal sous la forme d'un int, 0 si le ping répond, 1 sinon .
    void resultReady(int);

private:
    QProcess *pingProcess; //!< QProcess pour le ping.
    QString ipAdress;   //!< QString contenant l'adresse ip à tester.
    //! \fn run()OVERRIDE de la fonction run() de QThread
    //! Méthode pour la connection entre le ping et le thread et le travail à effectuer.
    void run() Q_DECL_OVERRIDE;

public slots:

    //! \fn Messaging()
    //! \brief Méthode qui recoit .
    //! \details Reçoit le signal du QProcess *pingProcess et l'emet sous la forme d'un int, 0 si le ping répond, 1 sinon.
    void Messaging(const int&, const QProcess::ExitStatus&);

};
#endif // PINGER

