#ifndef CONFIGCAMERA_H
#define CONFIGCAMERA_H
//!
//!\file configCamera.hpp
//!\brief Classe ConfigCamera, découvre et sauvegarde les cameras
//! \details Classe ConfigCamera, découvre et sauvegarde les cameras disponibles sur le réseau
//!\author PITAUD Antoine
//!\version 0.1
//!\date 02 Mai 2017
//!
//!\details La classe ConfigCamera lit et écrit dans les fichiers de configurations afin de tenir à jour la liste des cameras disponibles sur le reseau
//!
//!
#include "QString"
#include "iostream"
#include "istream"
#include "stdio.h"
#include "time.h"
#include "unistd.h"
#include "QDebug"
#include "fstream"
#include <sstream>
#include "pinger.hpp"
#include "QCoreApplication"
#include "QProcess"
#include "QVector"
#include "iterator"
#include <thread>
#include <QMap>
#include "camera.hpp"
#include "additional_functions.hpp"


//! \class ConfigCamera
//! \brief Découverte et sauvegarde des cameras disponibles.
//! \details La classe ConfigCamera lit et écrit dans les fichiers de configuration
//! afin de tenir à jour la liste des cameras disponibles sur le reseau.
//!
class ConfigCamera : public QObject
{
    Q_OBJECT
private:
    QVector<QString> urlsAvailable; //!< Vector Contenant les chaines de caractère des différents url de stream disponnibles
    QString allConfigFile;    //!< Chaîne de caractères contenant le chemin vers le fichier de configuration globale.
    QString currConfigFile;   //!< Chaîne de caractères contenant le chemin vers le fichier de configuration courant.
    QMap<QString, Camera*> mapDiscover; //!< QMap associant un nom de caméra à un pointeur vers une class Camera, les camera présentes dans cette liste vont être testées.
    QMap<QString, Camera*> mapDataCamera; //!< QMap associant un nom de caméra à un pointeur vers une class Camera, les cameras présentes dans cette liste sont disponibles.



public:

    static ConfigCamera& instance();

    //! \fn ConfigCamera()
    //! \brief Constructeur
    //! \details Constructeur par default de la classe
    ConfigCamera();

    //! \fn ConfigCamera(const QString&, const QString&)
    //! \brief Constructeur
    //! \details Constructeur de la classe prenant en paramètre les deux chemins vers les fichiers de configuration de camera,
    //! initialise les attributs allConfigFile, currConfigFile avec les QString passées en paramètre.
    //! \param const QString& chemin du fichier de configuration globale
    //! \param const QString& chemin du fichier de configuration courante
    ConfigCamera(const QString&, const QString&);

    //! \fn ~ConfigCamera()
    //! \brief Destructeur
    //! \details Destructeur de la classe et des éléments des QMap.
    ~ConfigCamera();

    //! \fn isOpenableAndReadable()
    //! \brief Vérifie les droits d'ouverture et d'écriture du fichier dont le chemin est pris en paramètre.
    //! \param const QString& chemin vers le fichier à vérifier.
    //! \return un boolean
    bool isOpenableAndReadable(const QString&) const;

    //! \fn currConfig()
    //! \brief Remplis la QMap mapDataCamera avec les informations contenues
    //!  dans le fichier de configuration courante qui a pour chemin currConfigFile.
    void currConfig();

    //! \fn pingAndConf()
    //! \brief Vérifie, découvre et sauvegarde les cameras sur le réseau.
    //! \details Dans un premier temps ping les Cameras présentes dans le la QMap mapDataCamera pour garantir leur disponnibilité.
    //! Dans un second temps utilise le Ping et le fichier de configuration globale pour découvrir les caméra sur le réseau.
    //! Cette fonction ping toutes les cameras présentes dans le fichier de configuration globales de façon asynchrone et non bloquante,
    //! utilise la QMap mapDataCamera et la méthode Ping() de différentes instances de camera à tester pour initialiser.
    void pingAndConf();

    //! \fn checkInfo()
    //! \brief Affiche les informations présentes dans la QMap mapDataCamera.
    void checkInfo() const;


    //! \fn configIsEmpty() const
    //! \brief Renvoie si la QMap mapDataCamera est vide.
    //! \return bool
    bool configIsEmpty() const;


    void refreshUrlsAvalaible();

    Q_INVOKABLE void initConfig();


    //! \fn CameraAvailable() const
    //! \brief Renvoie la référence de la QMap mapDataCamera.
    //! \return QMap<QString, Camera*>&
    QMap<QString, Camera*>& CameraAvailable() const;

    //! \fn ulrsAvailable() const
    //! \brief Renvoie la référence du QVector urlsAvailable.
    //! \return QVector&
    QVector<QString>& getUrlsAvailable();

    //! \fn Q_INVOKABLE QString urlAvailable() const
    //! \brief Renvoie une QString contenant l'url de stream d'une camera i.
    //! \return QString
    Q_INVOKABLE QString urlAvailable(int index);


    //! \fn Q_INVOKABLE int sizeConfig() const
    //! \brief Renvoi la taille de la mapDataCamera
    //! \return int
    Q_INVOKABLE int sizeConfig() const;
public slots:

    //! \fn deleteCamera(Camera*)
    //! \brief Récupère le signal toDestroy(Camera*) de la class Camera.
    //! \details Si le signal toDestroy(Camera*) est récupéré alors
    //! détruit la camera et libère la mémoire.
    void deleteCamera(Camera*);

    //! \fn addCamera(Camera*)
    //! \brief Récupère le signal toAdd(Camera*) de la class Camera.
    //! \details Si le signal toAdd(Camera*) est récupéré alors on ajoute la camera à la QMap mapDataCamera
    //! si celle-ci n'est pas déjà contenue dans cette map.
    void addCamera(Camera*);

signals:
    void urlsAvailableChanged(QVector<QString> newValue);
};

#endif // CONFIGCAMERA_H
