#include <iostream>

using namespace std ;

typedef struct S2d {
    double x = 0;
    double y = 0;
}S2d;

class Shape {
    S2d position;
    int size;
    char color[10];
    double longueur;
    double rayon;
};

class Simulation {
    int max;    
    S2d position;
    double epsil_zero;
    int nbAlg;
    int alg_birth_rate;
    int alg_life_max;
    int nbCor;
    int cor_life_max;
    double delta_l;
    int longueur;
    int alpha;
    double l_repro;
    double l_seg_interne;
    int dir_rot;
    int delta_rot;
    int nbSca;
    double r_sca;
    double r_sca_repro;
    int delta_r_sca;
    int sca_life_max;
    
};



class Model {

};



class Lifeform {

};


// typedef array<double,2> S2d;
// enum {x,y}

