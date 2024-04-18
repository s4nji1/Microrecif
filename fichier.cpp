#include <iostream>

using namespace std ;

class Simulation {
    int max;    
    double epsil_zero;
    double delta_l;
    int longueur;
    int alpha;
    double l_repro;
    double l_seg_interne;
    int dir_rot;
    int delta_rot;
};

class Lifeform : public Simulation {

};


class algues : public Lifeform{
    int nbAlg;
    int alg_birth_rate;
    int alg_life_max;
};

class coraux : public Lifeform{
    int nbCor;
    int cor_life_max;
};

class scavengers : public Lifeform{
    int nbSca;
    double r_sca;
    double r_sca_repro;
    int delta_r_sca;
    int sca_life_max;
};