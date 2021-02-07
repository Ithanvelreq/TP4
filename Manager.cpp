/*************************************************************************
                           Manager  -  description
                             -------------------
    d�but                : Decembre 2021
    copyright            : (C) 2021 par MDARHRI VELARDE
*************************************************************************/

//---------- R�alisation de la classe <Manager> (Manager.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;

//------------------------------------------------------ Include personnel
#include "Manager.h"
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
void Manager::fillGraph()
{
    vector<Data>::iterator it; //Iterateur sur decoder.infos
    pair<int, int> adjacence; //Element d'adjacence de la forme target referer
    pair<map<pair<int, int> , int>::iterator,bool> ret; //pair sur graph
    int target;
    int referer;

    for (it = decoder.infos.begin(); it<decoder.infos.end(); it++){
        target = (int) liens.find(it->target)->second;
        referer = (int) liens.find(it->referer)->second;
        adjacence = make_pair(target, referer);
        ret = graph.insert(make_pair(adjacence, 1));
        if(!ret.second){
            ret.first->second++;
        }
    }
}//fin de fillGraph()

void Manager::decode(ifstream & log, int time, int ext)
{
    decoder.Decode(log, time, ext);
}//fin de decode()

void Manager::fillCibleNbHits ()
{
    vector<Data>::iterator it; //Iterateur sur decoder.infos
    pair<map<int,int>::iterator,bool> ret; //pair sur cibleNbHits
    map<string,int>::iterator idx; // iterator sur liens
    pair<int, int> ins;

    for (it = decoder.infos.begin(); it<decoder.infos.end(); it++){
        idx = liens.find(it->target);
        ins = make_pair(idx->second, 1);
        ret = cibleNbHits.insert(ins);
        if(!ret.second){
            ret.first->second++;
        }
    }
}//fin de fillCibleNbHits


void Manager::findRanking(){
    map<int, int>:: iterator itcnh; // Iterateur sur cibleNbHits
    
    for(itcnh = cibleNbHits.begin(); itcnh!= cibleNbHits.end(); itcnh++){
        ranking.insert(make_pair(itcnh->second, itcnh->first));
    }
}//fin de findRanking()

void Manager::fillIndex ()
{
    vector<Data>::iterator itdata; //iterateur de decoder.infos
    pair<map<string,int>::iterator,bool> ret; //pair sur cibleNbHit

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
}//fin de fillIndex()


ofstream & Manager::writeDot(ofstream & os){
    long unsigned int i;
    map<pair<int, int> , int>::iterator it; //Iterateur sur graph

    os << "digraph {" << endl;

    for(i = 0; i < index.size(); i++){
        os << "node"<<i<<" [label=\""<< *index.at(i) << "\"]"<< endl;
    }

    for(it = graph.begin(); it!=graph.end(); it++){
        os <<"node"<< it->first.second <<" -> node" <<it->first.first << " [label=\"" <<  it->second << "\"]" << endl;
    }

    os << "}";
    return os;
}//fin de writeDot()


void Manager::writeRanking(int num)
{
    int i = 0;
    if( num == 0){
        num = ranking.size();
    }
    multimap<int, int>::reverse_iterator it = ranking.rbegin(); //Iterateur sur ranking
    while(i<num && it!=ranking.rend()){
        cout << *index.at(it->second) << " ( " << it->first << " hits)" << endl;
        i++;
        it++;
    }
}//fin de writeRanking(int num)
//-------------------------------------------- Constructeurs - destructeur
Manager::Manager ( const Manager & unManager )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Manager>" << endl;
#endif
} //----- Fin de Manager (constructeur de copie)


Manager::Manager ( )
{
    #ifdef MAP
        cout << "Appel au constructeur de <Manager>" << endl;
    #endif
} //----- Fin de Manager


Manager::~Manager ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Manager>" << endl;
#endif
} //----- Fin de ~Manager

