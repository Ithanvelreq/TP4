/*************************************************************************
                           Decoder  -  description
                             -------------------
    d�but                : 20/01/2021
    copyright            : (C) 2021 par VELARDE REQUENA MDARHRI
    e-mail               : ithan.velarde-requena@insa-lyon.fr taha.mdarhri@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Decoder> (fichier Decoder.h) ----------------
#if ! defined ( DECODER_H )
#define DECODER_H
//--------------------------------------------------- Interfaces utilis�es
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
// R�le de la classe <Decode>
//Classe qui permet de lire le fichier log et en extraire les informations.
//Ces derni�res sont mises dans une structure Data, qui est elle-m�me ins�r�e
//dans un vecteur de Data
//------------------------------------------------------------------------

class Decoder
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques

// type M�thode ( liste des param�tres );
	void Decode(ifstream & log, int time=30, int ext=0);
	//Extrait les informations


//-------------------------------------------- Constructeurs - destructeur
	Decoder();
	//Constructeur de la classe Decoder

	~Decoder();
	//Destructeur de la classe Decoder

//----------------------------------------------------- Attributs publics
	vector <Data> infos;
	//Vecteur compos�e des informations extraites du fichier log


//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- M�thodes prot�g�es
string extract(string & mot, char delim);
void clean(string & url);
int extension(string target);
//----------------------------------------------------- Attributs prot�g�s

};

//-------------------------------- Autres d�finitions d�pendantes de <DECODER>

#endif // DECODER_H
