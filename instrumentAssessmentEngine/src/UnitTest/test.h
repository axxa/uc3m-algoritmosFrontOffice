//
// Created by axxa on 9/5/20.
//

#ifndef INSTRUMENTASSESSMENTENGINE_TEST_H
#define INSTRUMENTASSESSMENTENGINE_TEST_H
#include "ZeroCoupon/zero_coupon_curve.h"
#include "PeriodCalc/Actual_360.h"
#include "PeriodCalc/_30_360.h"
#include "PeriodCalc/Actual_actual.h"
#include "Instrument/bond.h"
#include <iostream>
#include <ctime>
#include <string>
#include <vector>

class Test {
public:
    Test(int a){
        std::cout<< "Unit Test\n";
    }
    double testTema2(){
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
        return bond.getPresentValue();
    }

    double testBondActualActual(){
        //Datos basicos del bono-------------------------------------------------------
        vector<std::string> fechasZeroCouponString{"01/01/2019", "31/06/2019", "01/01/2020","31/06/2020",
                                                   "01/01/2021", "31/06/2021", "01/01/2022","31/06/2022"};
        vector<double> tiposZeroCoupon{0.05, 0.058, 0.064, 0.068,
                                       0.07, 0.078, 0.084, 0.098};
        double interesFijoAnual = 0.06;
        double nominal = 100;
        //---------------------------------------------------------------------

        std::string fechainicial = fechasZeroCouponString[0];
        std::string fechafinal = fechasZeroCouponString[fechasZeroCouponString.size()-1];
        vector<std::tm> fechasPagoZeroCoupon;

        //-----------construir la curva cero cupon--------------------------------------------------------
        auto convencion_360 = Actual_actual();
        for (auto element : fechasZeroCouponString)
            fechasPagoZeroCoupon.push_back(convencion_360.make_date(element));
        ZerocouponCurve<Actual_actual> zcc(convencion_360, fechasPagoZeroCoupon, tiposZeroCoupon);
        //------------------------------------------------------------------------------------------------

        Bond<Actual_actual> bond("bond", nominal, zcc, interesFijoAnual);
        bond.pricer();
        return bond.getPresentValue();
    }

    double testBondActual360(){
        //Datos basicos del bono-------------------------------------------------------
        vector<std::string> fechasZeroCouponString{"01/01/2019", "31/06/2019", "01/01/2020"};
        vector<double> tiposZeroCoupon{0.05, 0.058, 0.064};
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
        return bond.getPresentValue();

    }

    double testBond30_360(){
        //Datos basicos del bono-------------------------------------------------------
        vector<std::string> fechasZeroCouponString{"01/01/2019", "31/06/2019", "01/01/2020"};
        vector<double> tiposZeroCoupon{0.05, 0.058, 0.064};
        double interesFijoAnual = 0.06;
        double nominal = 100;
        //---------------------------------------------------------------------

        std::string fechainicial = fechasZeroCouponString[0];
        std::string fechafinal = fechasZeroCouponString[fechasZeroCouponString.size()-1];
        vector<std::tm> fechasPagoZeroCoupon;

        //-----------construir la curva cero cupon--------------------------------------------------------
        auto convencion_30_360 = _30_360();
        for (auto element : fechasZeroCouponString)
            fechasPagoZeroCoupon.push_back(convencion_30_360.make_date(element));
        ZerocouponCurve<_30_360> zcc(convencion_30_360, fechasPagoZeroCoupon, tiposZeroCoupon);
        //------------------------------------------------------------------------------------------------

        Bond<_30_360> bond("bond", nominal, zcc, interesFijoAnual);
        bond.pricer();
        return bond.getPresentValue();

    }
};


#endif //INSTRUMENTASSESSMENTENGINE_TEST_H
