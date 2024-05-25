#include <iostream>
#include <fstream>
#include <vector>
#include "lifeform.h"
#include "Simulation.h"
#include "../shape.h"
#include "constantes.h"
#include "message.h"

using namespace std;

void lecture_fichier() {
    ifstream f{"tests/t00.txt"};

    int nbAlg;
    f >> nbAlg;

    vector<Algue> algues;

    for (int i = 0; i < nbAlg; i++) {
        double x, y;
        int a;
        f >> x >> y >> a;
        Algue al(x, y, a);
        algues.push_back(al);
    }

    for (Algue al : algues) {
        // al.affiche();
        al.test_age();
        al.test_position();
    }

    int nbCor;
    f >> nbCor;

    vector<Corail> corails;

    for (int i = 0; i < nbCor; i++) {
        double xx, yy;
        int age, id, nbseg;
        int status, dir, dev;

        f >> xx >> yy >> age >> id >> status >> dir >> dev >> nbseg;

        Statut_cor Stat = static_cast<Statut_cor>(status);
        Dir_rot_cor Dir = static_cast<Dir_rot_cor>(dir);
        Statut_dev Dev = static_cast<Statut_dev>(dev);

        double *angle = new double[nbseg];
        double *longueur = new double[nbseg];

        for (int j = 0; j < nbseg; j++) {
            f >> angle[j];
            f >> longueur[j];
        }

        Corail c(xx, yy, age, id, Stat, Dir, Dev, nbseg, longueur, angle);
        corails.push_back(c);

        delete[] angle;
        delete[] longueur;
    }

    for (auto& coral : corails) {
        // coral.affiche();
        coral.test_age();
        coral.test_position_corail();
        coral.test_segement_length();
        coral.test_segement_angle();
        coral.test_duplicated_id(coral.get_id());
        vector<Segment> s = coral.get_seg();
        for (int i = 0; i < coral.get_nbrseg() - 1; i++) {
            s[i].test_segment_superposition(s[i + 1], coral.get_id());
        }
        for (int i = 0; i < coral.get_nbrseg(); i++) {
            for (int j = 0; j < nbCor; j++) {
                for (int k = 0; k < corails[j].get_nbrseg(); k++) {
                    if (corails[j].get_id() != coral.get_id() || s[i].index != corails[j].get_seg()[k].index) {
                        test_segment_collision(s[i], corails[j].get_seg()[k], coral.get_id(), corails[j].get_id());
                    }
                }
            }
        }          
    }

    int nbSca;
    f >> nbSca;

    vector<Scavenger> scavengers;

    for (int i = 0; i < nbSca; i++) {
        double x, y, r;
        int a, statutsca, id;
        f >> x >> y >> a >> r >> statutsca >> id;

        Statut_sca Stats = static_cast<Statut_sca>(statutsca);

        Scavenger s(x, y, a, r, Stats, id);
        scavengers.push_back(s);
    }

    for (auto& sca : scavengers) {
        // sca.affiche();
        sca.test_age();
        sca.test_position();
        sca.test_radius();
        sca.test_invalid_id();
    }
    
    ofstream g{"errors/out0.txt"};
    g << message::success() << endl ;
}
