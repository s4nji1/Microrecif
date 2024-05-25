#include "iostream"
#include <cmath>
#include "Modele/constantes.h"
#include "shape.h"
#include "Modele/message.h"

using namespace std;

Segment::Segment(){}

Segment::Segment(double a, double l, int idx) : angle(a), longueur(l), index(idx) {}


double Segment::ecartAngulaire(const Segment& seg) const {
    double angle1 = atan2(extr.y - base.y, extr.x - base.x);
    
    double angle2 = atan2(seg.extr.y - seg.base.y, seg.extr.x - seg.base.x);

    double deviation = angle2 - angle1;

    deviation = fmod(deviation + M_PI, 2 * M_PI) - M_PI;

    return deviation;
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
    } else if (val > epsil_zero) {
        return 1;
    } else {
        return 2;
    }
}

bool doIntersection(const Segment& seg1, const Segment& seg2) {
    int result1 = seg1.isAligned(seg1.base, seg2.base);
    int result2 = seg1.isAligned(seg1.base, seg2.extr);
    int result3 = seg2.isAligned(seg2.base, seg1.base);
    int result4 = seg2.isAligned(seg2.base, seg1.extr);

    if (result1 != result2 && result3 != result4) {
        return true;
    }

    if (result1 == 0 || result2 == 0 || result3 == 0 || result4 == 0) {
        return true;
    }

    return false;
}

void test_segment_collision(const Segment& seg1, const Segment& seg2, int id1, int id2) {
    if (doIntersection(seg1, seg2) == true) {
        ofstream f{"errors/out9.txt"};
        f << message::segment_collision(id1, seg1.index, id2, seg2.index) << endl;
    }
}

void Segment::test_segment_superposition(const Segment& seg, int id) {
    if (this->ecartAngulaire(seg) < epsil_zero) {
        ofstream f{"errors/out10.txt"};
        f << message::segment_superposition(id, this->index, seg.index) << endl ;
    }
}

