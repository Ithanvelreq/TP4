/*************************************************************************
                           Decoder  -  description
                             -------------------
    début                : 20/01/2021
    copyright            : (C) 2021 par VELARDE REQUENA MDARHRI
    e-mail               : ithan.velarde-requena@insa-lyon.fr taha.mdarhri@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Decoder> (fichier Decoder.h) ----------------
#if ! defined ( DECODER_H )
#define DECODER_H
//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <string>
#include <iostream>
using namespace std ;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
struct Data{
    string ipadd;
    string userlogname;
    string A_user;
    string date;
    int heure;
    string target;
    int status;
    int size;
    string referer;
    string clientID;
    Data(string ip="",string u="",string a="",string d="",int h =0, string t="",int st=0,int si=0,string r="",string c="") : ipadd(ip),userlogname(u), A_user(a),date(d),heure(h),target(t),status(st),size(si),referer(r),clientID(c) {}
};
//------------------------------------------------------------------------
// Rôle de la classe <Decode>
//Classe qui permet de lire le fichier log et en extraire les informations.
//Ces dernières sont mises dans une structure Data, qui est elle-même insérée
//dans un vecteur de Data
//------------------------------------------------------------------------

class Decoder
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

// type Méthode ( liste des paramètres );
	void Decode(ifstream & log, int time=30, int ext=0);
	//Extrait les informations


//-------------------------------------------- Constructeurs - destructeur
	Decoder();
	//Constructeur de la classe Decoder

	~Decoder();
	//Destructeur de la classe Decoder

//----------------------------------------------------- Attributs publics
	vector <Data> infos;
	//Vecteur composée des informations extraites du fichier log


//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Méthodes protégées
string extract(string & mot, char delim);
void clean(string & url);
int extension(string target);
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <DECODER>

#endif // DECODER_H
