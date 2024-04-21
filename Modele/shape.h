#ifndef SHAPE_H
#define SHAPE_H

#include "constantes.h"


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

    double ecartAngulaire(Segment A, Segment B){

        double vecAx = A.extr.x - A.base.x;
        double vecAy = A.extr.y - A.base.y;
        double vecBx = B.extr.x - B.base.x;
        double vecBy = B.extr.y - B.base.y;

        double dotProduct = vecAx * vecBx + vecAy * vecBy;
        double magA = sqrt( pow(vecAx,2) + pow(vecAy,2));
        double magB = sqrt( pow(vecBx,2) + pow(vecBy,2));

        double cosAlpha = dotProduct / (magA * magB);
        double alpha = acos(cosAlpha);

        return alpha;
    }
};

#endif