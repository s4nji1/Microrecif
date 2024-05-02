#include <iostream>
#include <fstream>
#include <random>
#include <cmath>
#include "../shape.h"
#include "../shape.cc"
#include "message.h"
#include "message.cc"
#include "lifeform.h"
#include "lifeform.cc"
#include "Simulation.h"
#include "Simulation.cc"
#include "constantes.h"


using namespace std ;

int main(){
    double a,l;
    Corail c(-1,-1,-1,1,DEAD,TRIGO,EXTEND,5,&l,&a);
    c.test_duplicated_id(5);
    return 0;
}