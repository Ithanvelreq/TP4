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

//------------------------------------------------------ Include personnel
#include "Manager.h"
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
void Manager::fillGraph()//Methode sans bug
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
}

void Manager::decode(ifstream & log, int time, int ext)
{
    decoder.Decode(log, time, ext);
}

void Manager::fillCibleNbHits ()//pas de bug
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
}


void Manager::findRanking(){ //Pas de bug
    map<int, int>:: iterator itcnh; // Iterateur sur cibleNbHits
    
    for(itcnh = cibleNbHits.begin(); itcnh!= cibleNbHits.end(); itcnh++){
        ranking.insert(make_pair(itcnh->second, itcnh->first));
    }
}

void Manager::fillIndex ()//Sans bug
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
}


ofstream & Manager::writeDot(ofstream & os){ //methode sans bug
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
}


void Manager::writeRanking(int num) //Methode sans bug
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
    multimap<int, int> ranking;
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
