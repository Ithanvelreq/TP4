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
    string timekey = "-t";
    string extkey = "-e";
    string graphkey = "-g";
    string dotkey = ".dot";
    string logkey = ".log";
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
            flagtime = atoi(argv[i]);
            if(flagtime < 0 || flagtime > 23){
                cerr << "Le creneau horaire doit etre compris entre 0 et 23!" << endl;
                return 2; // Code de cette erreur
            }

        }else if(!s.compare(extkey)){
            flagext = 1;

        }else if(!s.compare(graphkey)){
            i++;
            if(i == argc){
                cerr << "Fichier d'ecriture du graph pas specifie dans la bonne position ou pas specifie" << endl;
                cerr << "Pour rappel fichier d'ecriture du graph etre apres l'option -g" << endl;
                return 3; // Code de cette erreur
            }
            s.assign(argv[i]);
            if(s.rfind(dotkey) == string::npos){
                cerr << "Le fichier d'ecriture du graph ne se termine pas par .dot" << endl;
                cerr << "faut suivre cet exemple demo.dot" << endl;
                return 4; //Code de cette erreur
            }
            ofstream os;
            os.open(s);

            if(!os.is_open()){
                cerr << "Le fichier d'ecriture du graph de peut pas etre ouvert" << endl;
                os.close();
                return 5; //Code de cette erreur
            }
            flaggraph = 1;

        }else if(s.rfind(logkey) != string::npos){
            ifstream is;
            is.open(s);
            if(!is.is_open()){
                cerr << "Le fichier .log n'as pas pu etre ouvert, verifiez son nom svp" << endl;
                is.close();
                return 6; //Code de cette erreur
            }
            flaglog = 1;

        }else{
            cerr << "L'option " << s << " n'existe pas, veuillez consulter la documentation" << endl;
            return 7; //Code de cette erreur
        }
    }
    if(flaglog == -1){
        cerr << "Le fichier .log n'as pas ete indique, veuillez l'indiquer svp" << endl;
        return 8; //Code de cette erreur
    }
    cout << "tout c'est bien passe" << endl;
    manager.decode(is, flagtime, flagext);
    manager.fillIndex();
    manager.fillCibleNbHits();
    manager.findRanking();

    if(flaggraph){
        manager.fillGraph();
        manager.writeDot();
    }
    manager.writeRanking();

    return 0; //Pas d'erreur
}