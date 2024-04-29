#include <iostream>
#include <fstream>
#include "Simulation.h"

int Simulation::nbSim = 0;
int Simulation::nbAlg = 0;
int Simulation::nbCor = 0;
int Simulation::nbSca = 0;

void Simulation::lecture_fichier(string t1){
    ifstream fichier_lu;
    fichier_lu.open(t1);
    if( fichier_lu.is_open() ){
        cout << "Fichier lu" << endl ;
    }else{
        cout << "Erreur lors de la lecture du fichier" << endl ;
        exit(1);
    }
    fichier_lu.close();
}
