#include "iostream"
#include <cmath>
#include "Modele/constantes.h"
#include "shape.h"

Segment::Segment(){
        base.x = rand() % (int)(dmax - 2);  
        base.y = rand() % (int)(dmax - 2);
        extr.x = base.x + longueur * (cos(angle));
        extr.y = base.y + longueur * (sin(angle));
    }

// double Segment::ecartAngulaire(Segment &A, Segment &B){

//         double vx = A.extr.x - A.base.x;
//         double vy = A.extr.y - A.base.y;
//         double wx = B.extr.x - B.base.x;
//         double wy = B.extr.y - B.base.y;

//         double dotProduct = vx * wx + vy * wy;
//         double magA = sqrt( pow(vx,2) + pow(vy,2));
//         double magB = sqrt( pow(wx,2) + pow(wy,2));

//         double cosAlpha = dotProduct / (magA * magB);
//         double alpha = acos(cosAlpha);

//         return alpha;
// }

double Segment::ecartAngulaire(const Segment& seg) const {
        // Calcul de l'angle entre les segments
        double dotProduct = (extr.x - base.x) * (seg.extr.x - seg.base.x) + (extr.y - base.y) * (seg.extr.y - seg.base.y);
        double magA = hypot(extr.x - base.x, extr.y - base.y);
        double magB = hypot(seg.extr.x - seg.base.x, seg.extr.y - seg.base.y);
        double angle = acos(dotProduct / (magA * magB));

        // Normalisation de l'angle dans l'intervalle [-π, π]
        if (angle > M_PI) {
            angle -= 2 * M_PI;
        }

        return angle;
    }

bool Segment::intersection(const Segment& A, const Segment& B) {

        double x1 = A.base.x, y1 = A.base.y;
        double x2 = A.extr.x, y2 = A.extr.y;
        double x3 = B.base.x, y3 = B.base.y;
        double x4 = B.extr.x, y4 = B.extr.y;

        double denom = (y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1);
        double num1 = (x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3);
        double num2 = (x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3);

        // Vérifie si les segments sont parallèles ou confondus
        if (denom == 0) {
            if (num1 == 0 && num2 == 0) {
                // Les segments sont confondus
                return true;
            }
            // Les segments sont parallèles mais non confondus
            return false;
        }

        double t1 = num1 / denom;
        double t2 = num2 / denom;

        // Vérifie si le point d'intersection se situe à l'intérieur des segments
        if (t1 >= 0 && t1 <= 1 && t2 >= 0 && t2 <= 1) {
            return true;
        }

        return false;
    }

    double Segment::orientation(const S2d& p) const {
        return ((extr.x - base.x) * (p.y - base.y) - (p.x - base.x) * (extr.y - base.y));
    }

// Fonction pour vérifier si le point q est sur le segment pr
    bool Segment::isOnSegment(const S2d& q) const {
        S2d pr = {q.x - base.x, q.y - base.y};
        double pq_pr_dot = pr.x * (extr.x - base.x) + pr.y * (extr.y - base.y);
        double pr_length_squared = pr.x * pr.x + pr.y * pr.y;

        // Calcul de la projection de pq sur pr
        double projection = pq_pr_dot / pr_length_squared;

        // Vérification si q est sur pr avec une tolérance epsil_zero
        return (projection >= -epsil_zero && projection <= 1 + epsil_zero);
    }

    // Fonction pour détecter l'alignement de 3 points
    int Segment::isAligned(const S2d& p, const S2d& q) const {
        double val = orientation(q);

        if (std::abs(val) < epsil_zero && isOnSegment(q)) {
            return 0; // Les points sont alignés et q est sur le segment pr
        } else if (val > 0) {
            return 1; // Les points sont dans le sens anti-horaire
        } else {
            return 2; // Les points sont dans le sens horaire
        }
    }

    bool doIntersection(const Segment& seg1, const Segment& seg2) {
    int result1 = seg1.isAligned(seg1.base, seg2.base);
    int result2 = seg1.isAligned(seg1.base, seg2.extr);
    int result3 = seg1.isAligned(seg2.base, seg1.base);
    int result4 = seg1.isAligned(seg2.base, seg1.extr);

    if (result1 != result2 && result3 != result4) {
        // Les segments s'intersectent
        return true;
    }

    // Les segments ne s'intersectent pas, mais ils pourraient être alignés
    if (result1 == 0 || result2 == 0 || result3 == 0 || result4 == 0) {
        // Au moins un point est aligné avec l'autre segment
        return true;
    }

    return false;
}