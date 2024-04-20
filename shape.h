#include <iostream>
#include<math.h>

using namespace std;

struct S2d {
    double x = 0.0;
    double y = 0.0;
};

struct Segment {
    struct S2d points1;
    struct S2d points2;
};

struct Cercle {
    struct S2d centre;
    double rayon;
};

struct Carre {
    struct S2d pointc1;
    struct S2d pointc2;
    struct S2d pointc3;
    struct S2d pointc4;
};


typedef std::array<double, 2> S2d;

enum Coordonnee { X, Y };

struct Segment {
    struct S2d point1;
    struct S2d point2;
};

struct Cercle {
   struct S2d centre;
    double rayon;
};

struct Carre {
    struct S2d point1;
    struct S2d point2;
    struct S2d point3;
    struct S2d point4;
}; 
