/*************************************************************************
                           Manager  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <Manager> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Manager.h"
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
void fillGraph();

void decode(string log, int time, int ext)
{
    //decoder.decode(log, time, ext);
}

void fillCibleNbHits ()//Pas teste
{
    iterator<vector<Data>>it;
    for (it = decoder.infos.begin(); it<decoder.infos.end(); it++){
        pair<iterator<vector<Data>>, bool> p = fillCibleNbHits.insert(pair<string, int> (it->target, 1))
        if(!p.second){
            p.first->second++;
        }
    }
}


void findTop10();

void fillIndex ()//Pas teste
{
    iterator<vector<Data>> it;

    for (it = decoder.infos.begin(); it<decoder.infos.end(); it++){
        if(liens.insert(pair<string, int> (it->target, liens.size()).second)){
            index.push_back(&it->target);
        }
        if(liens.insert(pair<string, int> (it->referer, liens.size()).second){
            index.push_back(&it->referer);
        }   
    }
}


void writeDot();

void writeTop10()
{

}  
// type Manager::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


//------------------------------------------------- Surcharge d'op�rateurs
Manager & Manager::operator = ( const Manager & unManager )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Manager::Manager ( const Manager & unManager )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Manager>" << endl;
#endif
} //----- Fin de Manager (constructeur de copie)


Manager::Manager ( )
// Algorithme :
//
{
    //Decoder decoder;
    //Graph graph;
    map<int, int> cibleNbHits;
    multimap<int, int> top10;
    map<string, int> liens;
    vector<string*> index;
    #ifdef MAP
        cout << "Appel au constructeur de <Manager>" << endl;
    #endif
} //----- Fin de Manager


Manager::~Manager ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Manager>" << endl;
#endif
} //----- Fin de ~Manager


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
