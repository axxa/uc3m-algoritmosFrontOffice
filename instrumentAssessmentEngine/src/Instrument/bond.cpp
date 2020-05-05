//
// Created by axxa on 11/4/20.
//

#include "bond.h"

/*
Bond::Bond(double nominal, std::tm fechaPresente, std::tm fechaFinal,
            ZeroCoupon &zeroCoupon, double interesFijoAnual,
            std::string type) : Instrument(type) {
    std::cout<<"aca bond";
    this->zc=&zeroCoupon;
    this->nominal=nominal;
    this->fechaPresente=fechaPresente;
    this->fechaFinal=fechaFinal;
}*/

Bond::Bond(std::string type, double nominal, ZerocouponCurve &zcc, std::vector<std::tm> pagos,
           double interesFijoAnual) : Instrument(type) {
    std::cout<<"aca bond";
    this->zcc=&zcc;
    this->nominal=nominal;
    this->fechaPresente=fechaPresente;
    this->fechaFinal=fechaFinal;

}

void Bond::buildLegs() {

}
