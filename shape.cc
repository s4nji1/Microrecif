#include "iostream"
#include <cmath>
#include "Modele/constantes.h"
#include "shape.h"
#include "Modele/message.h"

using namespace std;

Segment::Segment(){
    this->extr.x = base.x + longueur * cos(angle);
    this->extr.y = base.y + longueur * sin(angle);
}

Segment::Segment(double a, double l) {
    angle = a;
    longueur = l;
}


double Segment::ecartAngulaire(const Segment& seg) const {
        double dotProduct = (extr.x - base.x) * (seg.extr.x - seg.base.x) + (extr.y - base.y) * (seg.extr.y - seg.base.y);
        double magA = hypot(extr.x - base.x, extr.y - base.y);
        double magB = hypot(seg.extr.x - seg.base.x, seg.extr.y - seg.base.y);
        double angle = acos(dotProduct / (magA * magB));

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

        if (denom == 0) {
            if (num1 == 0 && num2 == 0) {
                return true;
            }
            return false;
        }

        double t1 = num1 / denom;
        double t2 = num2 / denom;

        if (t1 >= 0 && t1 <= 1 && t2 >= 0 && t2 <= 1) {
            return true;
        }

        return false;
    }

    double Segment::orientation(const S2d& p) const {
        return ((extr.x - base.x) * (p.y - base.y) - (p.x - base.x) * (extr.y - base.y));
    }


    bool Segment::isOnSegment(const S2d& q) const {
        S2d pr = {q.x - base.x, q.y - base.y};
        double pq_pr_dot = pr.x * (extr.x - base.x) + pr.y * (extr.y - base.y);
        double pr_length_squared = pr.x * pr.x + pr.y * pr.y;

        double projection = pq_pr_dot / pr_length_squared;

        return (projection >= -epsil_zero && projection <= 1 + epsil_zero);
    }

    int Segment::isAligned(const S2d& p, const S2d& q) const {
        double val = orientation(q);

        if (std::abs(val) < epsil_zero && isOnSegment(q)) {
            return 0;
        } else if (val > 0) {
            return 1;
        } else {
            return 2;
        }
    }

    bool doIntersection(const Segment& seg1, const Segment& seg2) {
    int result1 = seg1.isAligned(seg1.base, seg2.base);
    int result2 = seg1.isAligned(seg1.base, seg2.extr);
    int result3 = seg1.isAligned(seg2.base, seg1.base);
    int result4 = seg1.isAligned(seg2.base, seg1.extr);

    if (result1 != result2 && result3 != result4) {
        return true;
    }

    if (result1 == 0 || result2 == 0 || result3 == 0 || result4 == 0) {
        return true;
    }

    return false;
}

void test_segment_collision(const Segment& seg1, const Segment& seg2, int id1, int id2){
    if (doIntersection(seg1, seg2)) {
        ofstream f{"out9.txt"};
        f << message::segment_collision(id1 ,id2 ,seg1.index,seg2.index);
    }
}

void Segment::test_segment_superposition(const Segment& seg, int id){
    if(Segment::ecartAngulaire(seg) < epsil_zero) {
        ofstream f{"out10.txt"};
        f << message::segment_superposition(id,seg.index,this->index);
    }
}
