//
// Created by axxa on 11/4/20.
//

#include "bond.h"

/*Bond::Bond(std::string type, double nominal, ZerocouponCurve<Actual_360> &zcc, double interesFijoAnual) : Instrument(type) {
    this->zcc=&zcc;
    this->nominal=nominal;
    this->fechaPresente=fechaPresente;
    this->fechaFinal=fechaFinal;
    this->interesFijoAnual = interesFijoAnual;
}*/
/*
void Bond::pricer() {
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
}*/
/*
double Bond::getPresentValue() {
    return this->pv;
}*/
