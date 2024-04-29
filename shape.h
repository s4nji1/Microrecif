#ifndef SHAPE_H
#define SHAPE_H

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

    Segment();
    // double ecartAngulaire(Segment&, Segment&);
    double ecartAngulaire(const Segment& ) const;
    bool intersection(const Segment&, const Segment&);
    double orientation(const S2d&)  const;
    // Fonction pour vérifier si le point q est sur le segment pr
    bool isOnSegment(const S2d& q) const ;
    // Fonction pour détecter l'alignement de 3 points
    int isAligned(const S2d& p, const S2d& q) const ;
    friend bool doIntersection(const Segment&, const Segment&);
};



#endif