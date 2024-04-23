#ifndef LIFEFORM_H
#define LIFEFORM_H

#include "constantes.h"

using namespace std;

class LifeForm {
    public:
    int age;
};

class Algue : public LifeForm {
    public:
    S2d position;
    Algue();
    ~Algue();
    void increment();
};

class Corail : public LifeForm {
    public:
    static int staticId;
    int id;
    enum Statut_cor status;
    enum Dir_rot_cor rotationDirection; //dir_rot
    enum Statut_dev developmentStatus;
    Segment segment;
    Corail();
    ~Corail();
    void increment();
};
int Corail::staticId = 0;

class Scavenger : public LifeForm {
    public:
    enum Statut_sca status;
    int r_sca;
    S2d position;
    Scavenger();
    ~Scavenger();
};

#endif