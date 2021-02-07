/*************************************************************************
                           Decoder  -  description
                             -------------------
    debut                : 20/01/2021
    copyright            : (C) 2021 par VELARDE REQUENA MDARHRI
    e-mail               : ithan.velarde-requena@insa-lyon.fr taha.mdarhri@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Decoder> (fichier Decoder.h) ----------------
#if ! defined ( DECODER_H )
#define DECODER_H
//--------------------------------------------------- Interfaces utilisees
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
// Role de la classe <Decode>
//Classe qui permet de lire le fichier log et en extraire les informations.
//Ces dernieres sont mises dans une structure Data, qui est elle-meme inseree
//dans un vecteur de Data
//------------------------------------------------------------------------

class Decoder
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques

// type Methode ( liste des parametres );
	void Decode(ifstream & log, int time=30, int ext=0);
	//Extrait les informations


//-------------------------------------------- Constructeurs - destructeur
	Decoder();
	//Constructeur de la classe Decoder

	~Decoder();
	//Destructeur de la classe Decoder

//----------------------------------------------------- Attributs publics
	vector <Data> infos;
	//Vecteur composee des informations extraites du fichier log


//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Methodes protegees
string extract(string & mot, char delim); //extrait une partie de la ligne
void clean(string & url); //Enleve ce qui pollue dans un lien
int extension(string target); //Enleve les extensions image, css, js si l'on veut

//----------------------------------------------------- Attributs proteges

};

//-------------------------------- Autres definitions dependantes de <DECODER>

#endif // DECODER_H
