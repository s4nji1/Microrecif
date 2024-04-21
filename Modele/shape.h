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

// Dot Product: The dot product of two vectors 
// 𝑣=(𝑣𝑥,𝑣𝑦)
// v=(vx ,vy​) and 𝑤=(𝑤𝑥,𝑤𝑦)in 2D space is calculated as:
// 𝑣⋅𝑤 = 𝑣𝑥 ⋅ 𝑤𝑥 + 𝑣𝑦 ⋅ 𝑤𝑦

// Magnitude of a Vector: The magnitude (or length) of a vector 
// 𝑣=(𝑣𝑥,𝑣𝑦) in 2D space is calculated using the Pythagorean theorem:
// ∥𝑣∥=sqrt(pow(𝑣𝑥,2)+pow(𝑣𝑦,2)​)

// Angle between Vectors: The cosine of the angle α
// α between two vectors can be calculated using the dot product and the magnitudes:
// cos(α)=𝑣⋅𝑤/∥𝑣∥.∥𝑤∥ 

// Given the cosine of the angle, you can find the angle itself using the inverse cosine function (arccosine):
// α=arccos⁡(𝑣⋅𝑤/∥𝑣∥.∥𝑤∥)


#endif