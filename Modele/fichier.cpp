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
    Scavenger sca1(2.5,3.5,-5,5,LIBRE,1);
    sca1.test_age();
    return 0;
}