//
// Created by axxa on 11/4/20.
//

#include <iostream>
#include <string>

#include "dialogo.h"
#include <UnitTest/test.h>

using namespace std;


void runTest(){
    double pv = 0;
    Test test(1);

    pv = test.testTema2().getPresentValue();
    cout<< "***testTema2: El valor presente del bono es: " << pv <<"***\n\n";
    pv = test.testBondActual360();
    cout<< "***testBondActual360: El valor presente del bono es: " << pv <<"***\n\n";
    pv = test.testBondActualActual();
    cout<< "***testBondActualActual: El valor presente del bono es: " << pv <<"***\n\n";
    pv = test.testBond30_360();
    cout<< "***testBond30_360: El valor presente del bono es: " << pv <<"***\n\n";
    pv = test.testTema2Swap();
    cout<< "***testTema2Swap: El valor presente del swap es: " << pv <<"***\n\n";
    auto tirValue = test.testTir();
    cout << "El valor de la TIR es: " << tirValue << endl;
}

void justOne(){
    Test test(1);
    auto pv = test.testTema2().getPresentValue();

    cout<< "***testTema2: El valor presente del bono es: " << pv <<"***\n\n";
}

int main() {
    //justOne();
    runTest();
    //Dialogo d(1);
    return 0;
}