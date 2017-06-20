#ifndef CAMERA_HPP
#define CAMERA_HPP

//!
//!\file Camera.hpp
//!\brief Classe Camera.hpp, contient ip et stream pour une camera available
//!\author PITAUD Antoine
//!\version 0.1
//!\date 09 Mai 2017
//!
//!\details Classe Camera.hpp, classe qui contient l'adresse ip, nom et l'url du stream pour une camera, sera gérer par une liste CameraAvailable. (work in progress)
//!
//!

#include "QProcess"
#include "QTimer"
#include "QDebug"
#include "QProcess"
#include "pinger.hpp"





//! \class Camera
//! \brief Gère les actions disponibles sur les cameras
//! \details Cette classe permet de stocker et de gérer les cameras.
//!
class Camera : public QObject
{
    Q_OBJECT

    Q_ENUMS(CameraStatus)


public:


    //!\enum CameraStatus
    //! \brief Enumération des trois états possible pour une Camera
    //! details La Camera est intialisée en l'état UNDEFINED, elle obtiendra l'état AVAILABLE
    //! en fonction de la réponse du ping.
    //! Statut placé automatiquement à AVAILABLE si déjà dans le fichier de configuration
    enum CameraStatus
    {
        AVAILABLE,
        NOTAVAILABLE,
        UNDEFINED
    };

    //! \fn Camera()
    //! \brief Constructeur
    //! \details Constructeur vide de la classe
    Camera();

    //! \fn Camera(const QString& , const QString&, const QString&)
    //! \brief Constructeur
    //! \details Constructeur avec initialisations des attributs ipAdress, urlStream et nameCamera, l'attribut enum_isAvailable est mis par default à NOTAVAILABLE.
    Camera(const QString& , const QString&, const QString&);

    //! \fn Camera(const QString& , const QString&, const QString&, const CameraStatus&)
    //! \brief Constructeur
    //! \details Constructeur avec initialisations des attributs ipAdress, urlStream, nameCamera et enum_isAvailable.
    Camera(const QString& , const QString&, const QString&, const CameraStatus&);

    //! \fn ~Camera()
    //! \brief Destructeur
    //! \details Destruit l'instance et libère la mémoire pour le Pinger*.
    ~Camera();

    //! \fn Ping()
    //! \brief Méthode pour pinger cette camera
    //! \details Ping la camera en vu de savoir si cette camera est disponible.
    void ping() const;

    //! \fn Availability() const
    //! \brief Accesseur en lecture du  statut de la camera.
    //! \return CameraStatus
    CameraStatus Availability() const;

    //! \fn setAvailability(const CameraStatus&)
    //! \brief Accesseur en écriture du status de la camera.
    //! \param const CameraStatus&
    void setAvailability(const CameraStatus&);

    //! \fn setIpAdress(const QString&)
    //! \brief Accesseur en écriture de l'adresse IP de la camera.
    //! \param const QString&
    void setIpAdress(const QString&);

    //! \fn getIpAdress() const
    //! \brief Accesseur en lecture de l'adresse ip de la camera.
    //! \return QString
    QString getIpAdress() const;

    //! \fn setUrlStream(const QString&)
    //! \brief Accesseur en écriture de l'url du stream.
    //! \param const QString&
    void setUrlStream(const QString&);

    //! \fn getUrlStream() const
    //! \brief Accesseur en lecture de l'url du stream.
    //! \return const QString&
    QString getUrlStream() const;

    //! \fn setNameCamera(const QString&)
    //! \brief Accesseur en écriture du nom de la camera.
    //! \param const QString&
    void setNameCamera(const QString&);

    //! \fn getNameCamera() const
    //! \brief Accesseur en lecture du nom de la camera.
    //! \return const QString&
    QString getNameCamera() const;


public slots:
    //! \fn pingRequest(int)
    //! \brief Fonction SLOT qui récupère un signal de la classe Pinger.
    //! \details Cette fonction reçoit le signal resultReady(int) qui est le résultat du ping.
    //! Si le ping a réussi pour une camera au statut UNDEFINED cette fonction emet le signal toAdd(Camera*) qui demande l'ajout de la camera courante
    //! à la QMap des cameras disponnibles.
    //! Si le ping échoue pour une camera au statut UNDEFINED alors envoie le signal toDestroy(Camera*).
    //! Si le ping échoue pour une camera au statut AVAILABLe alors change le statut pour NOTAVAILABLE.
    //! Si le ping réussi pour une camera au statut AVAILABLE alors ne fait rien.
     void pingRequest(int);

 signals:

     //! \fn toDestroy()
     //! \brief Signal qui envoie un pointeur Camera* (souvent this) pour demander sa destruction à la couche de configuration.
     //! \param Camera*
     void toDestroy(Camera*);
     //! \fn toAdd()
     //! \brief Signal qui envoie un pointeur Camera* (souvent this) pour demander son ajout à la QMap des cameras disponibles.
     //! \param Camera*
     void toAdd(Camera*);

private:
    QString ipAdress; //!< Chaîne de caractères contenant l'adresse IP de la camera.
    QString urlStream; //!< Chaîne de caractères contenant l'urls du stream disponble.
    QString nameCamera; //!< Chaîne de caractères contenant le nom de la camera.
    CameraStatus enum_isAvailable; //!< CameraStatus de disponibilité de la camera.
    Pinger *pingCamera;  //!< Pinger qui servira pour le test de disponibilité de la camera.


};

#endif // CAMERA_HPP

