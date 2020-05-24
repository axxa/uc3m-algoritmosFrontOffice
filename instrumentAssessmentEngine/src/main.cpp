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
    pv = test.testSwapActualActual();
    cout<< "***testSwapActualActual: El valor presente del swap es: " << pv <<"***\n\n";
    auto tirValue = test.testTir();
    cout << "El valor de la TIR es: " << tirValue << endl;
}


int main() {
    short opcion=0;
    cout<<"\n1. Correr test\n2. Correr dialogo\nSeleccione una opcion: ";
    cin>>opcion;
    if(opcion==1)
        runTest();
    else if(opcion==2)
        Dialogo d(1);
    else
        cout<<"Opcion incorrecta";
    return 0;
}