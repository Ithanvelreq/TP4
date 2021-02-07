#include <iostream>
#include <fstream>
#include <cstring>
#include "Manager.h"
int main(int argc, char * argv[])
{
    int i;
    int flagtime = -1;
    int flagext = -1;
    int flaggraph = -1;
    int flaglog = -1;
    int flagrank = 0;
    string timekey = "-t";
    string extkey = "-e";
    string graphkey = "-g";
    string dotkey = ".dot";
    string logkey = ".log";
    string rankkey = "-r";
    string source;
    string writedot;
    string s;
    Manager manager;
    for(i = 1; i<argc; i++){
        s.assign(argv[i]);
        if(!s.compare(timekey)){
            i++;
            if(i == argc){
                cerr << "Creneau horaire pas specifie dans la bonne position ou pas specifie" << endl;
                cerr << "Pour rappel le creneu horaire doit etre apres l'option -t" << endl;
                return 1; // Code de cette erreur
            }
            try{
                flagtime = stoi(argv[i]);
            }catch(const invalid_argument & e){
                cerr << "Veuillez rentrer un numero valide apres l'option -t svp" << endl;
                return 2; // Code de cette erreur
            }
            
            if(flagtime < 0 || flagtime > 23){
                cerr << "Le creneau horaire doit etre compris entre 0 et 23!" << endl;
                return 3; // Code de cette erreur
            }

            cout << "Prise en compte seulement des hits entre " << flagtime << "h et " << (flagtime +1) << "h" << endl;

        }else if(!s.compare(extkey)){
            flagext = 1;
            cout << "Fichiers de type css, image ou javascript ignores" << endl;

        }else if(!s.compare(graphkey)){
            i++;
            if(i == argc){
                cerr << "Fichier d'ecriture du graph pas specifie dans la bonne position ou pas specifie" << endl;
                cerr << "Pour rappel fichier d'ecriture du graph etre apres l'option -g" << endl;
                return 4; // Code de cette erreur
            }
            s.assign(argv[i]);
            if(s.rfind(dotkey) == string::npos){
                cerr << "Le fichier d'ecriture du graph ne se termine pas par .dot" << endl;
                cerr << "faut suivre cet exemple demo.dot" << endl;
                return 5; //Code de cette erreur
            }
            ofstream os;
            os.open(s);

            if(!os.is_open()){
                cerr << "Le fichier d'ecriture du graph de peut pas etre ouvert" << endl;
                os.close();
                return 6; //Code de cette erreur
            }
            flaggraph = 1;

        }else if(s.rfind(logkey) != string::npos){
            ifstream is;
            is.open(s);
            if(!is.is_open()){
                cerr << "Le fichier .log n'as pas pu etre ouvert, verifiez son nom svp" << endl;
                is.close();
                return 7; //Code de cette erreur
            }
            flaglog = 1;
        }else if(s.rfind(rankkey) != string::npos){
            i++;
            if(i == argc){
                cerr << "Nombre de resultats a afficher pas specifie dans la bonne position ou pas specifie" << endl;
                cerr << "Pour rappel le nombre doit etre apres l'option -r" << endl;
                return 8; // Code de cette erreur
            }
            try{
                flagrank = stoi(argv[i]);
            }catch(const invalid_argument & e){
                cerr << "Veuillez rentrer un numero valide apres l'option -r svp" << endl;
                return 9; // Code de cette erreur
            }
            
            if(flagrank <= 0){
                cerr << "Le nombre d'element a afficher doit etre superieur a 0!" << endl;
                return 10; // Code de cette erreur
            }

            cout << "Affichage des " << flagrank << " sites les plus visites" << endl;
        }else{
            cerr << "L'option " << s << " n'existe pas, veuillez consulter la documentation" << endl;
            return 11; //Code de cette erreur
        }
    }
    if(flaglog == -1){
        cerr << "Le fichier .log n'as pas ete indique, veuillez l'indiquer svp" << endl;
        return 12; //Code de cette erreur
    }
    cout << "tout c'est bien passe" << endl;
    /*
    manager.decode(is, flagtime, flagext);
    manager.fillIndex();
    manager.fillCibleNbHits();
    manager.findRanking();

    if(flaggraph){
        manager.fillGraph();
        manager.writeDot();
    }
    manager.writeRanking();
    */

    return 0; //Pas d'erreur
}