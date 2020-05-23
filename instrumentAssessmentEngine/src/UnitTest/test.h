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
#include "Instrument/swap.h"
#include "Tir/tir.h"
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "utils.h"

class Test {
public:
    Test(int a){
        std::cout<< "Unit Test\n";
    }
    Bond<Actual_360> testTema2(){
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


        auto xVals = zcc.getCalibrada().getInterpolatedMaturityVector();
        auto yVals = zcc.getCalibrada().getInterpolatedInterestVector();
        utils u(1);
        u.showTimeSeries(xVals, yVals);
        return bond;
    }

    double testTema2Swap(){
        //Datos basicos del bono-------------------------------------------------------
        //vector<std::string> fechasZeroCouponString{"01/04/2016","03/10/2016", "03/04/2017", "02/10/2017","02/04/2018"};
        //vector<double> tiposZeroCoupon{0.048,0.0474, 0.05, 0.051, 0.052};
        vector<std::string> fechasZeroCouponString{"03/10/2016", "03/04/2017", "02/10/2017","02/04/2018"};
        vector<double> tiposZeroCoupon{0.0474, 0.05, 0.051, 0.052};
        double euriborEnReset = 0.48;
        double interesFijoAnual = 0.05;
        double nominal = 100;
        //---------------------------------------------------------------------


        std::string fechafinal = fechasZeroCouponString[fechasZeroCouponString.size()-1];
        vector<std::tm> fechasPagoZeroCoupon;

        //-----------construir la curva cero cupon--------------------------------------------------------
        auto convencion_360 = Actual_360();
        std::tm fechainicial = convencion_360.make_date("01/04/2016");
        for (auto element : fechasZeroCouponString)
            fechasPagoZeroCoupon.push_back(convencion_360.make_date(element));
        ZerocouponCurve<Actual_360> zcc(convencion_360, fechasPagoZeroCoupon, tiposZeroCoupon);
        //------------------------------------------------------------------------------------------------

        Swap<Actual_360> swap("swap", nominal, zcc, interesFijoAnual, fechainicial, euriborEnReset);
        swap.pricer();

        auto xVals = zcc.getCalibrada().getInterpolatedMaturityVector();
        auto yVals = zcc.getCalibrada().getInterpolatedInterestVector();
        utils u(1);
        u.showTimeSeries(xVals, yVals);

        return swap.getPresentValue();
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

    double testTir(){
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

        return tir.computeTir(0, 10);

    }
};


#endif //INSTRUMENTASSESSMENTENGINE_TEST_H
