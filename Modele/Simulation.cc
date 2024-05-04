#include <iostream>
#include <fstream>
#include "Simulation.h"


void lecture_fichier(){
    ifstream f{"t1.txt"};

    double x;
    double y;
    int age;

    f >> x;
    f >> y;
    f >> age;

    Algue a(x,y,age);

    cout << "position x : " << x << endl;
    cout << "position y : " << y << endl;
    cout << "age : " << age << endl;
    
    a.test_age();

}