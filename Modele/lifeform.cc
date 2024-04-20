#include <iostream>
#include <fstream>
#include <random>
#include <cmath>
#include "shape.h"
#include "constantes.cc"
#include "message.h"
#include "Simulation.cc"

using namespace std;

class LifeForm {
    public:
    int age;
};

class Algue : public LifeForm {
    public:
    S2d position;
    Algue(){
        position.x = rand() % (int)(dmax - 2);
        position.y = rand() % (int)(dmax - 2);
        age = 0;
        Simulation::nbAlg++;
        cout << "Algue constructed, Total = " << Simulation::nbAlg << endl ;
    }
    ~Algue(){
        Simulation::nbAlg--;
        cout << "Algue destroyed, Total = " << Simulation::nbAlg << endl ;
    }
    void increment(){
        age++;
        if( age = max_life_alg ){
            this->~Algue();
        }
    }
};

class Corail : public LifeForm {
    public:
    static int staticId;
    int id;
    enum Statut_cor status;
    enum Dir_rot_cor rotationDirection; //dir_rot
    enum Statut_dev developmentStatus;
    Segment segments[];
    Corail(){
        segments.x = rand() % (int)(dmax - 2);
        segments.y = rand() % (int)(dmax - 2);
        age = 0;
        id = staticId;
        staticId++;
        status = Statut_cor::ALIVE;
        rotationDirection = Dir_rot_cor::TRIGO;
        developmentStatus = Statut_dev::EXTEND;
        Simulation::nbCor++;
        cout << "Corail constructed, Total = " << Simulation::nbCor << endl ;
    }
    ~Corail(){
        Simulation::nbCor--;
        cout << "Corail destroyed, Total = " << Simulation::nbCor << endl ;
    }
    void increment(){
        age++;
        if( age = max_life_cor ){
            this->~Corail();
        }

    }
};
int Corail::staticId = 0;

class Scavenger : public LifeForm {
    public:
    enum Statut_sca status;
    int r_sca;
    S2d position;
    Scavenger(){
        position.x = rand() % (int)(dmax - 2);
        position.y = rand() % (int)(dmax - 2);
        age = 0;
        status = Statut_sca::LIBRE;
        r_sca = r_sca;
        Simulation::nbSca++;
        cout << "Scavenger constructed, Total = " << Simulation::nbSca << endl ;
    }
    ~Scavenger(){
        Simulation::nbSca--;
        cout << "Scavenger destroyed, Total = " << Simulation::nbSca << endl ;
    }
};