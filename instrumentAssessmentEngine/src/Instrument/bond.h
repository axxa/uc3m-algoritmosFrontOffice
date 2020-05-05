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
        //explicit Bond(double nominal, std::tm fechaFinal,ZeroCoupon &zeroCoupon, std::string type);
        explicit Bond(std::string type, double nominal, ZerocouponCurve &zcc, std::vector<std::tm> pagos,
                      double interesFijoAnual);
        void buildLegs();
    private:
        double nominal;
        tm fechaPresente;
        tm fechaFinal;
        ZerocouponCurve *zcc;
        vector<leg> legs;

};


#endif //INSTRUMENTASSESSMENTENGINE_BOND_H
