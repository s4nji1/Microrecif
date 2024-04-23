#include <iostream>
#include <fstream>
#include <random>
#include <cmath>
#include "Simulation.h"
#include "constantes.h"
#include "../shape.h"
#include "lifeform.h"

Algue::Algue(){
        position.x = rand() % (int)(dmax - 2);
        position.y = rand() % (int)(dmax - 2);
        age = 0;
        Simulation::nbAlg++;
        cout << "Algue constructed, Total = " << Simulation::nbAlg << endl ;
    }
Algue::~Algue(){
        Simulation::nbAlg--;
        cout << "Algue destroyed, Total = " << Simulation::nbAlg << endl ;
    }

void Algue::increment(){
        age++;
        if( age = max_life_alg ){
            this->~Algue();
        }
    }

Corail::Corail(){
        segment.base.x;
        segment.base.y;
        segment.extr.x;
        segment.extr.y;
        age = 0;
        id = staticId;
        staticId++;
        status = Statut_cor::ALIVE;
        rotationDirection = Dir_rot_cor::TRIGO;
        developmentStatus = Statut_dev::EXTEND;
        Simulation::nbCor++;
        cout << "Corail constructed, Total = " << Simulation::nbCor << endl ;
    }
Corail::~Corail(){
        Simulation::nbCor--;
        cout << "Corail destroyed, Total = " << Simulation::nbCor << endl ;
    }
void Corail::increment(){
        age++;
        if( age = max_life_cor ){
            this->~Corail();
        }

    }

Scavenger::Scavenger(){
        position.x = rand() % (int)(dmax - 2);
        position.y = rand() % (int)(dmax - 2);
        age = 0;
        status = Statut_sca::LIBRE;
        r_sca = r_sca;
        Simulation::nbSca++;
        cout << "Scavenger constructed, Total = " << Simulation::nbSca << endl ;
    }
Scavenger::~Scavenger(){
        Simulation::nbSca--;
        cout << "Scavenger destroyed, Total = " << Simulation::nbSca << endl ;
    }