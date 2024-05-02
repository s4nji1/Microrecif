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

}

LifeForm::LifeForm(double x, double y, int a){
    age = a;
    position.x = x;
    position.y = y;
}

void LifeForm::test_age(){
    if( age <= 0 ){
        cout << message::lifeform_age(age) << endl ;
        exit(EXIT_FAILURE);
    }
}

void LifeForm::test_position(){
    if( position.x < 1 || position.x > dmax - 1 || position.y < 1 || position.y > dmax - 2 ){
        cout << message::lifeform_center_outside(position.x, position.y) << endl ;
        exit(EXIT_FAILURE);
    }
}

void Corail::test_position(){
    if( get_x() <= 0 || get_x() >= dmax || get_y() <= 0 || get_y() >= dmax ){
        cout << message::lifeform_computed_outside(id, get_x(), get_y()) << endl ;
        exit(EXIT_FAILURE);
    }
}

Algue::Algue(double x, double y, int age) : LifeForm(x,y,age){

}

Algue::Algue(){};

Algue::~Algue(){}

Corail::Corail(){}

Corail::Corail(double x, double y, int age, int id_, enum Statut_cor Statut, enum Dir_rot_cor Dir_rot,enum Statut_dev Statut_dev, int nbseg, double *longueur, double *angle) : LifeForm(x,y,age) {
    id = id_;
    nbrseg = nbseg;
    
    seg = new Segment[nbrseg];
    for(int i = 0; i < nbrseg; i++){
        seg[i].angle = angle[i];
        seg[i].longueur = longueur[i];
    }
}

void Corail::test_segement_angle(){
    for(int i = 0; i < nbrseg ; i++){
        if( seg[i].angle < -M_PI || seg[i].angle > M_PI ){
            cout << message::segment_angle_outside(id, seg[i].angle) << endl ;
            exit(EXIT_FAILURE);
        }
    }
}

void Corail::test_segement_length(){
    for(int i = 0; i < nbrseg ; i++){
        if( seg[i].longueur < l_repro - l_seg_interne || seg[i].longueur > l_repro ){
            cout << message::segment_length_outside(id, seg[i].longueur) << endl ;
            exit(EXIT_FAILURE);
        }
    }
}

int Corail::get_index_id_s(){
        return index_id_s;
    }

int* Corail::get_id_s(){
        return id_s;
    }

int Corail::get_id(){
        return id;
    }

int Corail::get_nbrseg(){
        return nbrseg;
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

Corail::~Corail(){
        Simulation::nbCor--;
        cout << "Corail destroyed, Total = " << Simulation::nbCor << endl ;
}

void Corail::test_duplicated_id(int d){
    for(int i = 0; i < index_id_s ; i++){
        if(id_s[i] == d){
            cout << message::lifeform_duplicated_id(id) << endl ;
        }
    }
}

Scavenger::Scavenger(){
        
}

Scavenger::~Scavenger(){
        
    }

Scavenger::Scavenger(double x, double y, int age, double r, enum Statut_sca statut, int id) : LifeForm(x,y,age){
    status = statut;
    corail_id_cible = id;
    rayon = r;
}

void Scavenger::test_radius(){
    if( rayon < r_sca || rayon > r_sca_repro ){
        cout << message::scavenger_radius_outside(rayon) << endl ;
        exit(EXIT_FAILURE);
    }
}

int Scavenger::aux_invalid_id(){
    Corail c;
    int i = 0;
    int *tab = c.get_id_s();
    int size = c.get_index_id_s();
    while(i < size){
        if(tab[i] == corail_id_cible){
            return 1;
        }
        i++;
    }  
    return 0; 
}

void Scavenger::test_invalid_id(){
    if(aux_invalid_id() == 0){
        cout << message::lifeform_invalid_id(corail_id_cible) << endl;
    }
}
