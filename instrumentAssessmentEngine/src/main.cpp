//
// Created by axxa on 11/4/20.
//

#include "PeriodCalc/Actual_360.h"
#include <iostream>
#include <string>
#include <UnitTest/test.h>
#include "Tir/tir.h"

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

}

void testTir(){
    Test test(1);
    //Datos basicos del bono-------------------------------------------------------
    vector<std::string> fechasZeroCouponString{"01/01/2019", "31/06/2019", "01/01/2020","31/06/2020"};
    vector<double> tiposZeroCoupon{0.05, 0.058, 0.064, 0.068};
    double interesFijoAnual = 0.06;
    double nominal = 100;
    //---------------------------------------------------------------------

    std::string fechainicial = fechasZeroCouponString[0];

    std::string fechafinal = fechasZeroCouponString[fechasZeroCouponString.size()-1];
    vector<std::tm> fechasPagoZeroCoupon;

    //-----------construir la curva cero cupon--------------------------------------------------------
    auto convencion_360 = Actual_360();
    for (auto element : fechasZeroCouponString)
        fechasPagoZeroCoupon.push_back(convencion_360.make_date(element));
    ZerocouponCurve<Actual_360> zcc(convencion_360, fechasPagoZeroCoupon, tiposZeroCoupon);
    //------------------------------------------------------------------------------------------------

    Bond<Actual_360> bond("bond", nominal, zcc, interesFijoAnual);
    bond.pricer();

    std::tm fechaReset = convencion_360.make_date(fechainicial);
    vector<double> prices = bond.getPrices();
    Tir<Actual_360> tir = Tir<Actual_360>(convencion_360, fechasPagoZeroCoupon,fechaReset,prices);
    tir.setMarketValue(bond.getPresentValue());

    /*
    for(int i = 0 ; i < prices.size(); i++){
        short yearCount = 0;

        if(i != 0){
            yearCount = convencion_360.compute_daycount_by_convention(fechaReset,fechasPagoZeroCoupon[i]);
            yearCount /= short(convencion_360.dias_anio());
        }

        tir.addCupon(yearCount, prices[i]);
    }*/
    cout << "El valor de la TIR es: " << tir.computeTir(0, 10) << endl;

}
int main() {

    //runTest();
    testTir();
    return 0;
}