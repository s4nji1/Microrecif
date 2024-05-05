#include <iostream>
#include <fstream>
#include <vector>
#include "Simulation.h"
#include "constantes.h"

using namespace std;


void lecture_fichier(){
    ifstream f{"t1.txt"};

    int nbAlg;
    f >> nbAlg;

    vector<Algue> algues;

    for(int i = 0; i < nbAlg; i++){
        double x, y;
        int a;
        f >> x >> y >> a;
        Algue al(x, y, a);
        algues.push_back(al);
    }

    for(Algue al : algues){
        al.affiche();
    }

    int nbCor;
    f >> nbCor;

    vector<Corail> corails;

    for(int i = 0; i < nbCor; i++){
        double  xx, yy ;
        int age, id, nbseg;
        int status, dir, dev;

        f >> xx >> yy >> age >> id >> status >> dir >> dev >> nbseg;

        Statut_cor Stat = static_cast<Statut_cor>(status);
        Dir_rot_cor Dir = static_cast<Dir_rot_cor>(dir);
        Statut_dev Dev = static_cast<Statut_dev>(dev);

        double *angle = new double[nbseg];
        double *longueur = new double[nbseg];

        for(int j = 0; j < nbseg; j++){
            f >> longueur[j];
            f >> angle[j];
        }

        Corail c(xx, yy, age, id, Stat, Dir, Dev, nbseg, longueur, angle);
        corails.push_back(c);

        delete[] angle;
        delete[] longueur;
    }

    for (auto coral : corails) {
        coral.affiche();
    }

    int nbSca;
    f >> nbSca;

    vector<Scavenger> scavengers;

    for(int i = 0; i < nbSca; i++){
        double x, y, r;
        int a, statutsca, id;
        f >> x >> y >> a >> r >> statutsca >> id;

        Statut_sca Stats = static_cast<Statut_sca>(statutsca);

        Scavenger s(x, y, a, r, Stats, id);
        scavengers.push_back(s);

    }

    for (auto sca : scavengers) {
        sca.affiche();
    }

}
