#include <iostream>
#include <fstream>
#include <random>
#include <cmath>
#include "constantes.cc"

typedef struct S2d {
    double x ;
    double y ;
}S2d;

class Segment{
    public:
    S2d base;
    S2d extr;
    double angle;
    double longueur;
    Segment(){
        base.x = rand() % (int)(dmax - 2);
        base.y = rand() % (int)(dmax - 2);
        extr.x = base.x + longueur * (cos(angle));
        extr.y = base.y + longueur * (sin(angle));
    }
};
