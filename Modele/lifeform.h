#ifndef LIFEFORM_H
#define LIFEFORM_H

using namespace std;

class LifeForm {
    int age;
    S2d position;
    public:
    LifeForm();
    LifeForm(int ,double ,double);
    int get_age();
    double get_x();
    double get_y();
    void check_age();
    void check_position();
    void check_computed_position();
};

class Algue : public LifeForm {
    public:
    S2d position;
    Algue();
    ~Algue();
    void increment();
};

class Corail : public LifeForm {
    static int staticId;
    int *id_tab;
    int id;
    int nb_seg;
    Segment *seg;
    enum Statut_cor status;
    enum Dir_rot_cor rotationDirection; //dir_rot
    enum Statut_dev developmentStatus;
    Segment segment;
    public :
    Corail();
    Corail(int , int ,int ,int ,int ,Segment*);
    ~Corail();
    void increment();
    int *get_id_tab();
    int get_id();
    int get_staticId();
    int get_nb_seg();
    Segment *get_seg();
    enum Statut_cor get_status();
    enum Dir_rot_cor get_rotationDirection();
    enum Statut_dev get_developmentStatus();
    Segment get_segment();
    void check_segement_length();
    void check_segement_angle();
    void check_computed_position();
};

class Scavenger : public LifeForm {
    public:
    enum Statut_sca status;
    int rayon;
    S2d position;
    Scavenger();
    ~Scavenger();
    void check_radius();
};

#endif