//
// Created by axxa on 11/4/20.
//

#ifndef UC3M_ALGORITMOSFRONTOFFICE_ZEROCOUPONCURVE_H
#define UC3M_ALGORITMOSFRONTOFFICE_ZEROCOUPONCURVE_H


#include "PeriodCalc/Actual_360.h"
#include "zero_coupon.h"

class ZerocouponCurve {
    public:
        explicit ZerocouponCurve(Actual_360 convencion, std::tm fechaInicial){
            cout<<"Constructor ZerocouponCurve";
            this->convecion= convencion;
            this->fechaInicial = fechaInicial;
        };
        void addZeroCoupon(std::tm fechaFinal, double interest, Actual_360 actual)
        {
            auto yearCount = actual.compute_daycount(this->fechaInicial, fechaFinal)/360;
            ZeroCoupon zc(yearCount, fechaFinal, interest);
            this->vectorZeroCoupon.push_back( zc );
        }

    private:
        Actual_360 convecion;
        std::tm fechaInicial;
        std::vector<ZeroCoupon> vectorZeroCoupon;

};

#endif //UC3M_ALGORITMOSFRONTOFFICE_ZEROCOUPONCURVE_H
