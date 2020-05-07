//
// Created by axxa on 11/4/20.
//

#include "Instrument/instrument.h"
#include "Instrument/bond.h"
#include "PeriodCalc/Actual_360.h"
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "ZeroCoupon/zero_coupon_curve.h"
#include "spline.h"


using namespace std;

void testBondActual360(){
    //Datos basicos del bono-------------------------------------------------------
    vector<std::string> fechasZeroCouponString{"01/01/2019", "31/06/2019", "01/01/2019","31/06/2020"};
    vector<double> tiposZeroCoupon{0.05, 0.058, 0.064, 0.068};
    double interesFijoAnual = 0.06;
    double nominal = 100;
    //---------------------------------------------------------------------

    std::string fechainicial = fechasZeroCouponString[0];
    std::string fechafinal = fechasZeroCouponString[fechasZeroCouponString.size()-1];
    vector<std::tm> fechasPagoZeroCoupon;

    //-----------construir la curva cero cupon--------------------------------------------------------
    auto convencion_360 = Actual_360();
    std::tm fechaPresente = convencion_360.make_date(fechainicial);
    for (auto element : fechasZeroCouponString)
        fechasPagoZeroCoupon.push_back(convencion_360.make_date(element));

    ZerocouponCurve zcc(convencion_360, fechasPagoZeroCoupon, tiposZeroCoupon);


    Bond bond("bond", nominal, zcc, interesFijoAnual);
    bond.pricer();
    cout<< bond.getPresentValue() << "....asdadsa";

    //cout << "a:" << spline(2018);
    //------------------------------------------------------------------------------------------------

}
int main() {
    //Bond bond("Bond");
    testBondActual360();
    return 0;

}