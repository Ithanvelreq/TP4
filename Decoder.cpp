/*************************************************************************
                           Decoder  -  description
                             -------------------
    début                : 20/01/2021
    copyright            : (C) 2021 par VELARDE REQUENA MDARHRI
    e-mail               : ithan.velarde-requena@insa-lyon.fr taha.mdarhri@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Decoder> (fichier Decoder.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
#include <fstream>
#include<vector>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Decoder.h"

//------------------------------------------------------------- Constantes
#define TAILLE 400
//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
void Decoder::Decode(ifstream & log, int time, int ext){
int i=0;
	string mot ;
	getline(log, mot);
	while(log.peek() != EOF){
		Data d;
		d.ipadd = extract(mot,' ');
		d.userlogname = extract(mot,' ');
		d.A_user = extract(mot,' ');
		extract(mot,'[');
		d.date = extract(mot,':');
		d.heure = stoi(extract(mot,':'));
		extract(mot,'"');
		extract(mot,' ');
		d.target = extract(mot,' ');
		clean(d.target);
		extract(mot,' ');
		d.status = stoi(extract(mot,' '));
		string tmp = extract(mot,' ');
		if(isdigit(tmp[0])){
		d.size = stoi(tmp);
		}else{
		d.size = -1;
		}
		extract(mot,'"');
		d.referer = extract(mot,'"');
		clean(d.referer);
		extract(mot,'"');
		d.clientID = extract(mot,'"');		
		if ( ((ext && !extension(d.target)) || !ext) && ( (time<0 || time>23) || ( (time>=0 && time<=23) && d.heure==time) ) ){
		infos.push_back(d);
		}
		getline(log,mot);
		i++;
	}
	if(i==0){
	cout<< "Le fichier est vide"<<endl;
	}
}
//-------------------------------------------- Constructeurs - destructeur
Decoder::Decoder( )
{
	#ifdef MAP
		cout << "Appel au constructeur de <Decoder>" << endl;
	#endif
	
} //----- Fin de Decoder

Decoder::~Decoder()
{
    #ifdef MAP
		cout << "Appel au destructeur de <Decoder>" << endl;
	#endif
} //-----Fin de ~Decoder
//------------------------------------------------------------------ PRIVE
string Decoder::extract(string & mot, char delim){
	int i = mot.find(delim);
	string extrait = mot.substr(0,i);
	mot = mot.substr(i+1);
	return extrait;
}

void Decoder::clean(string & url){
//if(!strcmp("http://intranet-if.insa-lyon.fr",url.substr(0,31))){
if(!url.substr(0,31).compare("http://intranet-if.insa-lyon.fr")){
url =url.substr(31);
}
int i = url.find('?');
url = url.substr(0,i);
i = url.find(';');
url = url.substr(0,i);
}

int Decoder::extension(string target){
int i = target.find('.');
string ext = target.substr(i+1);
if(!ext.compare("gif") || !ext.compare("ico") || !ext.compare("css") || !ext.compare("jpg") || !ext.compare("png") || !ext.compare("js") ){
return 1; 
}else{
return 0;
}
}

//----------------------------------------------------- Méthodes protégées









