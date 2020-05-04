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


using namespace std;

void testBondActual360(){
    std::string fechainicial = "01/01/2019";
    std::string fechafinal = "01/01/2021";
    double nominal = 1000;
    vector<std::tm> fechasPagoZeroCoupon;
    vector<std::string> fechasZeroCouponString{"01/01/2019", "01/01/2020", "01/01/2021"};

    //-----------construir la curva cero cupon--------------------------------------------------------
    auto actual = Actual_360();
    std::tm fechaPresente = actual.make_date(fechainicial);
    ZerocouponCurve zcc(actual, fechaPresente);

    //estas vendrian siendo las fechas del maturity
    for (auto element : fechasZeroCouponString)
        fechasPagoZeroCoupon.push_back(actual.make_date(element));
    //luego se construye los tipos (%) cero coupon
    vector<double> tiposZeroCoupon{0.05, 0.058, 0.064, 0.068};

    for (int i = 0; i < fechasPagoZeroCoupon.size(); ++i) {
        zcc.addZeroCoupon(fechasPagoZeroCoupon[i], tiposZeroCoupon[i], actual);
    }

    //------------------------------------------------------------------------------------------------

}
int main() {
    //Bond bond("Bond");
    testBondActual360();
    return 0;

}