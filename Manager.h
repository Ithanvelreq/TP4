/*************************************************************************
                           Manager  -  description
                             -------------------
    debut                : Decembre 2020
    copyright            : (C) 2021 par MDARHRI VELARDE
*************************************************************************/

//---------- Interface de la classe <Manager> (fichier Manager.h) ------
#if ! defined ( MANAGER_H )
#define MANAGER_H

//--------------------------------------------------- Interfaces utilisees
using namespace std;
#include "Decoder.h"
#include<fstream>
#include <map>
#include <iterator>
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types
//------------------------------------------------------------------------ 
// Role de la classe <Manager>
// Cette classe se charge de produire l'affichage a l'ecran des pages web et leurs
// hits par ordre decroissant. Il est aussi charge de creer le .dot dans 
// lequel les donnes pour faire un graphe figurent
//------------------------------------------------------------------------ 

class Manager
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Methodes publiques
    void fillGraph();
    // Rempli notre graphe sous forme d'une liste adjacence avec les donnes extraites
    // par le decodeur

    void decode(ifstream & log, int time, int ext);
    // Cette methode decode le fichier .log ouvert par log

    void fillCibleNbHits ();
    // Cette methode remplis notre map qui contiens chaque page web avec
    // son nombre de hits correspondant

    void findRanking();
    // Transforme notre map qui contiens chaque page web avec
    // son nombre de hits correspondant dans une multimap
    // triee en fonction du nombre de hits de chaque page

    void fillIndex ();
    // Remplis notre map liens qui a chaque page associe un index unique 
    // et notre vecteur index qui a chaque index associe un pointeur sur
    // le nom de la page contenu dans liens

    ofstream & writeDot(ofstream & os); //Changer en ofstream
    // Ecris le .dot a partir de notre liste d'adjacence
    // et de liens

    void writeRanking( int num);
    // Affiche les num premieres pages avec le plus de hits
    // si num=0 alors affiche toutes les pages


//-------------------------------------------- Constructeurs - destructeur
    Manager ( const Manager & unManager );
  
    Manager ( );
   
    ~Manager ( );
   

//------------------------------------------------------------------ PRIVE 
protected:
//----------------------------------------------------- Attributs proteges
    Decoder decoder;
    map<pair<int, int> , int> graph; // List d'adjecence de la forme (target, referer), nbhits
    map<int, int> cibleNbHits; // map des pages avec ces hits correspondants de la forme indice sur target, nbhits
    multimap<int, int> ranking; //ranking des pages qui ont le plus de hits de la forme nbhits, indice sur target
    map<string, int> liens; // Liste des pages web associes a leur indice unique de la forme target, index
    vector<string *> index; // Vecteur que a chaque indice associe un pointeur sur target
};

#endif // MANAGER_H
