//
// Created by axxa on 11/4/20.
//

#ifndef INSTRUMENTASSESSMENTENGINE_BOND_H
#define INSTRUMENTASSESSMENTENGINE_BOND_H
#include "instrument.h"
#include "ZeroCoupon/zero_coupon_curve.h"
#include "leg.h"
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

class Bond: public Instrument{

    public:
        explicit Bond(std::string type, double nominal, ZerocouponCurve<Actual_360> &zcc, double interesFijoAnual);
        void pricer();
        double getPresentValue();
    private:
        double nominal;
        tm fechaPresente;
        tm fechaFinal;
        ZerocouponCurve<Actual_360> *zcc;
        double pv;
        double interesFijoAnual;

};


#endif //INSTRUMENTASSESSMENTENGINE_BOND_H
