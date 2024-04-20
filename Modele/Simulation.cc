#include <iostream>
#include <fstream>
#include <random>
#include <cmath>
#include "shape.h"
#include "constantes.cc"
#include "message.h"

class Simulation {
    public:
    static int nbSim;
    static int nbAlg;
    static int nbCor;
    static int nbSca;
};

int Simulation::nbSim = 0;
int Simulation::nbAlg = 0;
int Simulation::nbCor = 0;
int Simulation::nbSca = 0;
