//
// Created by axxa on 11/4/20.
//

#include "PeriodCalc/Actual_360.h"
#include <iostream>
#include <string>
#include <UnitTest/test.h>


using namespace std;



void swapTest(){
    //fechas de pago
    //nominal
    //forma en q se calcularan los flujos
        //IRS-Interest Rate Swaps   :   Cambiar flujos fijos por flotantes
        //Cross Currency Swaps      :   Comprar protección contra riesgo de crédito CDS.
        //CDS-Credit defult Swaps   :   Cambiar flujos de caja entre divisas
    double interesFijo= 0.05;
    double interesFlotanteEnFirma=0.048; //ej: Euribor 6M --> semianual
    double nominal;
    std::string formaPago = "Semianual";
    Actual_360 convencion = Actual_360();

}
int main() {
    double pv = 0;
    Test test(1);
    pv = test.testTema2();
    cout<< "\n***testTema2: El valor presente del bono es: " << pv <<"***\n";
    pv = test.testBondActual360();
    cout<< "\n***testBondActual360: El valor presente del bono es: " << pv <<"***\n";
    pv = test.testBondActualActual();
    cout<< "\n***testBondActualActual: El valor presente del bono es: " << pv <<"***\n";
    pv = test.testBond30_360();
    cout<< "\n***testBond30_360: El valor presente del bono es: " << pv <<"***\n";

    return 0;
}