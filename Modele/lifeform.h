#ifndef LIFEFORM_H
#define LIFEFORM_H

#include "constantes.h"
#include <fstream>
#include "../shape.h"
#include "Simulation.h"


using namespace std;

class LifeForm {
    int age;
    S2d position;
    public:
    LifeForm();
    LifeForm(double, double, int);
    int get_age();
    double get_x();
    double get_y();
    void test_age();
    void test_position();
};

class Algue : public LifeForm {
    public:
    Algue();
    Algue(double, double, int);
    ~Algue();
    void affiche();
};

class Corail : public LifeForm {
    static int index_id_s;
    static int *id_s;
    int id;
    int nbrseg;
    vector<Segment> seg;
    enum Statut_cor status;
    enum Dir_rot_cor rotationDirection;
    enum Statut_dev developmentStatus;
    public :
    Corail();
    Corail(double, double, int, int, enum Statut_cor, enum Dir_rot_cor ,enum Statut_dev ,int ,double* ,double*);
    ~Corail();
    int get_index_id_s();
    int *get_id_s();
    int get_id();
    int get_nbrseg();
    vector<Segment> get_seg();
    enum Statut_cor get_status();
    enum Dir_rot_cor get_rotationDirection();
    enum Statut_dev get_developmentStatus();
    Segment get_segment();
    void test_segement_length();
    void test_segement_angle();
    void test_position_corail();
    void test_duplicated_id(int);
    void affiche();
};

class Scavenger : public LifeForm {
    enum Statut_sca status;
    double rayon;
    int corail_id_cible;
    public:
    enum Statut_sca get_status();
    int get_rayon();
    int get_corail_id_cible();
    Scavenger();
    Scavenger(double, double, int, double, enum Statut_sca, int);
    ~Scavenger();
    void test_radius();
    int aux_invalid_id();
    void test_invalid_id();
    void affiche();
};

#endif