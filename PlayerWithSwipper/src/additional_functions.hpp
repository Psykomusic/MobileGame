#ifndef ADDITIONAL_FUNCTIONS_HPP
#define ADDITIONAL_FUNCTIONS_HPP

#include <string>
#include <vector>
#include <string>
#include <pthread.h>
#include <queue>
#include <iostream>
#include <unistd.h>
#include <ctime>
#include <map>
#include <stdlib.h>
#include <time.h>
#include <sys/times.h>
#include <vector>
#include <regex>
//#include <syscall.h>
#include <algorithm>
//#include <sys/dir.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <QTimer>
#include <QTime>
#include <QtWidgets/QApplication>

using namespace std;
//!
//! \fn vector<string> split(string data, string separateur)
//! \brief Fonction additionnelle de split
//! \details Fonction permettant diviser une chaîne de caractères avec un séparateur
//! ATTENTION : Le séparateur est supprimé des chaînes contenues dans le vecteur de retour.
//! \param data : chaîne à diviser, contenant un ou des séparateurs (ex : "premier,deuxième,troisième")
//! \param separateur : chaîne contenant le séparateur (ex : ",")
//! \return Retourne un vecteur de type "string", contenant chaque sous-chaîne splittée (ex : vector[0] = "premier", vector[1]="deuxième", etc.)
//!
vector<string> split(string data, string separateur);

//!
//! \fn vector<string> split(string data, char separateur)
//! \brief Fonction additionnelle de split
//! \details Fonction permettant diviser une chaîne de caractères avec un séparateur
//! ATTENTION : Le séparateur est supprimé des chaînes contenues dans le vecteur de retour.
//! \param data : chaîne à diviser, contenant un ou des séparateurs (ex : "premier,deuxième,troisième")
//! \param separateur : caractère contenant le séparateur (ex : '\n')
//! \return Retourne un vecteur de type "string", contenant chaque sous-chaîne splittée (ex : vector[0] = "premier", vector[1]="deuxième", etc.)
//!
vector<string> split(string data, char separateur);


//! \fn delay(int)
//! \brief Fonction additionnelle de delay
//! \details Fonction permattant d'attendre un certain nombre de seconde sans bloquer la fenêtre principale.
//! \param int sec : nombre de seconde à attendre.
//!
void delay(int);
#endif // ADDITIONAL_FUNCTIONS_HPP

