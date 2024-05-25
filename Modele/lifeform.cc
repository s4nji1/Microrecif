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
        ofstream f{"errors/out1.txt"};
        f << message::lifeform_age(age) << endl ;
        exit(EXIT_FAILURE);
    }
}

void LifeForm::test_position(){
    if( position.x < 1 || position.x > dmax - 1 || position.y < 1 || position.y > dmax - 2 ){
        ofstream f{"errors/out2.txt"};
        f << message::lifeform_center_outside(position.x, position.y) << endl ;
        exit(EXIT_FAILURE);
    }
}

void Corail::test_position_corail(){
    if( get_x() <= 0 || get_x() >= dmax || get_y() <= 0 || get_y() >= dmax ){
        ofstream f{"errors/out3.txt"};
        f << message::lifeform_computed_outside(id, get_x(), get_y()) << endl ;
        exit(EXIT_FAILURE);
    }
}

Algue::Algue(double x, double y, int age) : LifeForm(x,y,age){

}

void Algue::affiche(){
    cout << "x : " << this->get_x() << endl ;
    cout << " y : " << this->get_y() << endl ;
    cout << " age : " << this->get_age() << endl << endl ;
}

Algue::Algue(){};

Algue::~Algue(){}

Corail::Corail(){}

int* Corail::id_s = new int[20];
int Corail::index_id_s = 0;

Corail::Corail(double x, double y, int age, int id_, enum Statut_cor Statut, enum Dir_rot_cor Dir_rot,enum Statut_dev Statut_dev, int nbseg, double *longueur, double *angle) : LifeForm(x,y,age) {
    id = id_;
    id_s[index_id_s] = id;
    index_id_s++;
    nbrseg = nbseg;
    status = Statut;
    rotationDirection = Dir_rot;
    developmentStatus = Statut_dev;
    for (int i = 0; i < nbrseg; i++) {
        seg.push_back(Segment(angle[i], longueur[i], i));
        if (i == 0) {
            seg[i].base.x = x;
            seg[i].base.y = y;
        } else {
            seg[i].base.x = seg[i - 1].extr.x;
            seg[i].base.y = seg[i - 1].extr.y;
        }
        seg[i].extr.x = seg[i].base.x + seg[i].longueur * cos(seg[i].angle);
        seg[i].extr.y = seg[i].base.y + seg[i].longueur * sin(seg[i].angle);
    }
}


string statusToString(Statut_cor status) {
    if (status == DEAD) return "DEAD";
    else return "ALIVE";
}

string directionToString(Dir_rot_cor direction) {
    if (direction == TRIGO) return "TRIGO";
    else return "INVTRIGO";
}

string developmentToString(Statut_dev development) {
    if (development == EXTEND) return "EXTEND";
    else return "REPRO";
}


void Corail::affiche(){
    cout << "x : " << this->get_x() << endl;
    cout << " y : " << this->get_y() << endl;
    cout << "age : " << this->get_age() << endl;
    cout << "id : " << this->get_id() << endl;
    cout << "status : " << statusToString(this->status) << endl;
    cout << "rotationDirection : " << directionToString(this->rotationDirection) << endl;
    cout << "developmentStatus : " << developmentToString(this->developmentStatus) << endl;
    cout << "nbrseg : " << this->get_nbrseg() << endl;
    for (const auto& segment : this->seg ){
        cout << "angle : " << segment.angle << endl; 
    }
    for (const auto& segment : this->seg ){
        cout << "longueur : " << segment.longueur << endl; 
    }
    cout << endl; 
}

void Corail::test_segement_angle(){
    for(int i = 0; i < nbrseg ; i++){
        if( seg[i].angle < -M_PI || seg[i].angle > M_PI ){
            ofstream f{"errors/out4.txt"};
            f << message::segment_angle_outside(id, seg[i].angle) << endl ;
            exit(EXIT_FAILURE);
        }
    }
}

void Corail::test_segement_length(){
    for(int i = 0; i < nbrseg ; i++){
        if( seg[i].longueur < l_repro - l_seg_interne || seg[i].longueur >= l_repro ){
            ofstream f{"errors/out5.txt"};
            f << message::segment_length_outside(id, seg[i].longueur) << endl ;
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

vector<Segment> Corail::get_seg(){
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

Corail::~Corail(){}

void Corail::test_duplicated_id(int d){
    int k = 0;
    for(int i = 0; i < index_id_s ; i++){
        if(id_s[i] == d){
            k++;
        }
    }
    if(k > 1){
        ofstream f{"errors/out6.txt"};
        f << message::lifeform_duplicated_id(id) << endl ;
        exit(EXIT_FAILURE);
    }
}

enum Statut_sca Scavenger::get_status(){
    return status;
}

int Scavenger::get_rayon(){
    return rayon;
}
int Scavenger::get_corail_id_cible(){
    return corail_id_cible;
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

string statutToString(Statut_sca s_sca) {
    if (s_sca == LIBRE) return "LIBRE";
    else return "MANGE";
}

void Scavenger::affiche(){
    cout << "x : " << this->get_x() << endl ;
    cout << " y : " << this->get_y() << endl ;
    cout << " age : " << this->get_age() << endl ;
    cout << " rayon : " << this->get_rayon() << endl;
    cout << "Statut : " << statutToString(this->status) << endl ;
    cout << "Id cible : " << this->get_corail_id_cible() << endl << endl ;
}


void Scavenger::test_radius(){
    if( rayon < r_sca || rayon >= r_sca_repro ){
        ofstream f{"errors/out7.txt"};
        f << message::scavenger_radius_outside(rayon) << endl ;
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
        ofstream f{"errors/out8.txt"};
        f << message::lifeform_invalid_id(corail_id_cible) << endl;
    }
}
