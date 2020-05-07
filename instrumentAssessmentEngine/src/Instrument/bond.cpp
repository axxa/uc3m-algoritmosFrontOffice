//
// Created by axxa on 11/4/20.
//

#include "bond.h"

Bond::Bond(std::string type, double nominal, ZerocouponCurve &zcc, double interesFijoAnual) : Instrument(type) {
    std::cout<<"aca bond";
    this->zcc=&zcc;
    this->nominal=nominal;
    this->fechaPresente=fechaPresente;
    this->fechaFinal=fechaFinal;
    this->interesFijoAnual = interesFijoAnual;
}

void Bond::pricer() {
    auto maturity_gap = this->zcc->getMaturityGap();
    for (auto element : this->zcc->getVectorZeroCoupon()) {
        std::cout<< "C: " << nominal * this->interesFijoAnual * 1/maturity_gap;
        element.pricer(nominal * this->interesFijoAnual * 1/maturity_gap);
        this->pv += element.getPrice();
    }
}

double Bond::getPresentValue() {
    return this->pv;
}
