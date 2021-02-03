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
void Manager::fillGraph(){}

void Manager::decode(string log, int time, int ext)
{
    //decoder.decode(log, time, ext);
}

void Manager::fillCibleNbHits ()//Sans bug
{
    vector<Data>::iterator it; //Iterateur sur decoder.infos
    pair<map<int,int>::iterator,bool> ret; //Iterateur sur cibleNbHits
    map<string,int>::iterator idx;
    pair<int, int> ins;

    for (it = decoder.infos.begin(); it<decoder.infos.end(); it++){
        idx = liens.find(it->target);
        ins = make_pair(idx->second, 1);
        ret = cibleNbHits.insert(ins);
        if(!ret.second){
            ret.first->second++;
        }
    }
}


void Manager::findTop10(){}

void Manager::fillIndex ()//Sans bug
{
    vector<Data>::iterator itdata; //iterateur de decoder.infos
    pair<map<string,int>::iterator,bool> ret;

    for (itdata = decoder.infos.begin(); itdata<decoder.infos.end(); itdata++){

        ret = liens.insert(pair<string, int> (itdata->target, liens.size()));
        if(ret.second){
            index.push_back((string *) &(ret.first->first));
        }

        ret = liens.insert(pair<string, int> (itdata->referer, liens.size()));
        if(ret.second){
            index.push_back((string *) &(ret.first->first));
        }   
    }
}


void Manager::writeDot(){}

void Manager::writeTop10()
{

}  
// type Manager::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


//------------------------------------------------- Surcharge d'op�rateurs
//Manager & Manager::operator = ( const Manager & unManager )
// Algorithme :
//
//{
//} //----- Fin de operator =


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
