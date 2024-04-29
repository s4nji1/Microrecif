#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <fstream>

using namespace std;

class Simulation {
    public:
    static int nbSim;
    static int nbAlg;
    static int nbCor;
    static int nbSca;
    void lecture_fichier(string);
};



#endif