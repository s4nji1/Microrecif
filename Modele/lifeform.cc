#include <iostream>
#include <fstream>
#include <random>
#include <cmath>
#include "Simulation.h"
#include "constantes.h"
#include "../shape.h"
#include "lifeform.h"
#include "message.h"

int LifeForm::get_age(){
        return age;
    }

double LifeForm::get_x(){
        return position.x;
    }

double LifeForm::get_y(){
        return position.y;
    }

LifeForm::LifeForm(){
    position.x = rand() % (int)(dmax - 2);
    position.y = rand() % (int)(dmax - 2);
    age = 0;
}

LifeForm::LifeForm(int a, double x, double y){
    age = a;
    position.x = x;
    position.y = y;
}

void LifeForm::check_age(){
    if( age <= 0 ){
        cout << message::lifeform_age(age) << endl ;
        exit(EXIT_FAILURE);
    }
}

void LifeForm::check_position(){
    if( position.x < 1 || position.x > dmax - 1 || position.y < 1 || position.y > dmax - 2 ){
        cout << message::lifeform_center_outside(position.x, position.y) << endl ;
        exit(EXIT_FAILURE);
    }
}

void Corail::check_computed_position(){
    if( get_x() <= 0 || get_x() >= dmax || get_y() <= 0 || get_y() >= dmax ){
        cout << message::lifeform_computed_outside(id, get_x(), get_y()) << endl ;
        exit(EXIT_FAILURE);
    }
}

Algue::Algue(){
        Simulation::nbAlg++;
        cout << "Algue constructed, Total = " << Simulation::nbAlg << endl ;
    }
Algue::~Algue(){
        Simulation::nbAlg--;
        cout << "Algue destroyed, Total = " << Simulation::nbAlg << endl ;
    }

// void Algue::increment(){
//         age++;
//         if( age = max_life_alg ){
//             this->~Algue();
//         }
//     }

Corail::Corail(){
        // segment.base.x;
        // segment.base.y;
        // segment.extr.x;
        // segment.extr.y;
        id = staticId;
        staticId++;
        status = Statut_cor::ALIVE;
        rotationDirection = Dir_rot_cor::TRIGO;
        developmentStatus = Statut_dev::EXTEND;
        Simulation::nbCor++;
        cout << "Corail constructed, Total = " << Simulation::nbCor << endl ;
    }

Corail::Corail(int a, int b,int c,int d,int e,Segment *f) : LifeForm(a,b,c) {
    id = d;
    nb_seg = e;
    seg = new Segment[nb_seg];
    for(int i = 0; i < nb_seg; i++){
        seg[i] = f[i];
    }
}

void Corail::check_segement_angle(){
    for(int i = 0; i < nb_seg; i++){
        if( seg[i].angle < -M_PI || seg[i].angle > M_PI ){
            cout << message::segment_angle_outside(id, seg[i].angle) << endl ;
            exit(EXIT_FAILURE);
        }
    }
}

void Corail::check_segement_length(){
    for(int i = 0; i < nb_seg; i++){
        if( seg[i].longueur < l_repro - l_seg_interne || seg[i].longueur > l_repro ){
            cout << message::segment_length_outside(id, seg[i].longueur) << endl ;
            exit(EXIT_FAILURE);
        }
    }
}



int* Corail::get_id_tab(){
        return id_tab;
    }

int Corail::get_id(){
        return id;
    }

int Corail::get_staticId(){
        return staticId;
    }

int Corail::get_nb_seg(){
        return nb_seg;
    }

Segment* Corail::get_seg(){
        return seg;
    }

enum Statut_cor Corail::get_status(){
        return status;
    }

enum Dir_rot_cor Corail::get_rotationDirection(){
        return rotationDirection;
    }

enum Statut_dev Corail::get_developmentStatus(){
        return developmentStatus;
    }

Segment Corail::get_segment(){
        return segment;
    }

Corail::~Corail(){
        Simulation::nbCor--;
        cout << "Corail destroyed, Total = " << Simulation::nbCor << endl ;
    }

// void Corail::increment(){
//         LifeForm::get_age()++;
//         if( LifeForm::get_age() = max_life_cor ){
//             this->~Corail();
//         }

//     }

int Corail::staticId = 0;

Scavenger::Scavenger(){
        // position.x = rand() % (int)(dmax - 2);
        // position.y = rand() % (int)(dmax - 2);
        // age = 0;
        status = Statut_sca::LIBRE;
        rayon = r_sca;
        Simulation::nbSca++;
        cout << "Scavenger constructed, Total = " << Simulation::nbSca << endl ;
    }

Scavenger::~Scavenger(){
        Simulation::nbSca--;
        cout << "Scavenger destroyed, Total = " << Simulation::nbSca << endl ;
    }

void Scavenger::check_radius(){
    if( rayon < r_sca || rayon > r_sca_repro ){
        cout << message::scavenger_radius_outside(rayon) << endl ;
        exit(EXIT_FAILURE);
    }
}