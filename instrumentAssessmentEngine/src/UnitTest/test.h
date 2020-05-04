//
// Created by axxa on 4/5/20.
//

#ifndef INSTRUMENTASSESSMENTENGINE_TEST_H
#define INSTRUMENTASSESSMENTENGINE_TEST_H
#include "Instrument/instrument.h"
#include "Instrument/bond.h"
#include "PeriodCalc/Actual_360.h"
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "ZeroCoupon/zero_coupon_curve.h"

using namespace std;

class test {
    public:
        test(){
            this->a= 1;
            cout<<"Build class UnitTest";
        };
    static void testBondActual360(){
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
        auto yearCount = actual.compute_daycount(fechainicial, fechafinal)/360;

        //------------------------------------------------------------------------------------------------

    }
        int getA(){
            return a;
        };
    private:
        int a;
};


#endif //INSTRUMENTASSESSMENTENGINE_TEST_H
