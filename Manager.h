/*************************************************************************
                           Manager  -  description
                             -------------------
    debut                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Manager> (fichier ${file_name}) ------
#if ! defined ( MANAGER_H )
#define MANAGER_H

//--------------------------------------------------- Interfaces utilisees
using namespace std;
#include "Decoder.h"
//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Role de la classe <Manager>
//
//
//------------------------------------------------------------------------ 

class Manager : public Ancetre
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Methodes publiques

    void fillGraph();
    // type Methode ( liste de parametres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void decode(string log, int time, int ext);
    // type Methode ( liste de parametres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void fillCibleNbHits ();
    // type Methode ( liste de parametres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void findTop10();
    // type Methode ( liste de parametres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void fillIndex ();
    // type Methode ( liste de parametres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void writeDot();
    // type Methode ( liste de parametres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void writeTop10();
    // type Methode ( liste de parametres );
    // Mode d'emploi :
    //
    // Contrat :
    //



//------------------------------------------------- Surcharge d'operateurs

//-------------------------------------------- Constructeurs - destructeur
    Manager ( const Manager & unManager );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Manager ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Manager ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Methodes protegees

private:
//------------------------------------------------------- Methodes privees

protected:
//----------------------------------------------------- Attributs proteges
//Decoder decoder;
//Graph graph;
map<int, int> cibleNbHits;
multimap<int, int> top10;
map<string, int> liens;
vector<string*> index;

private:
//------------------------------------------------------- Attributs prives

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privees

//----------------------------------------------------------- Types prives

};

//----------------------------------------- Types dependants de <Manager>

#endif // MANAGER_H