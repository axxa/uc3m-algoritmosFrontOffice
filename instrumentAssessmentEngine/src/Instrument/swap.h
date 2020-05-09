//
// Created by axxa on 11/4/20.
//

#ifndef INSTRUMENTASSESSMENTENGINE_SWAP_H
#define INSTRUMENTASSESSMENTENGINE_SWAP_H


#include <memory>
#include "instrument.h"
#include "ZeroCoupon/zero_coupon_curve.h"

using namespace std;

template <class T>
class Swap :public Instrument{

public:
    Swap(std::string type, double nominal, ZerocouponCurve<T> &zcc, double interesFijoAnual): Instrument(type) {
            this->zcc=&zcc;
            this->nominal=nominal;
            this->fechaPresente=fechaPresente;
            this->fechaFinal=fechaFinal;
            this->interesFijoAnual = interesFijoAnual;
    }
    void pricer(){
        auto maturity_gap = this->zcc->getMaturityGap();
        std::vector<ZeroCoupon> zcv = this->zcc->getVectorZeroCoupon();
        for(int i = 0; i< zcv.size(); i++){
            double c = nominal * this->interesFijoAnual * maturity_gap;
            if(i == zcv.size() - 1){
                c+=nominal;
            }
            zcv[i].pricer(c);
            this->pv += zcv[i].getPrice();
        }
    }
    double getPresentValue(){
        return this->pv;
    }
    private:
        double nominal;
        tm fechaPresente;
        tm fechaFinal;
        ZerocouponCurve<T> *zcc;
        double pv;
        double interesFijoAnual;
};


#endif //INSTRUMENTASSESSMENTENGINE_SWAP_H
