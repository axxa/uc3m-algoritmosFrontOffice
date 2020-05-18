//
// Created by axxa on 11/4/20.
//

#ifndef INSTRUMENTASSESSMENTENGINE_BOND_H
#define INSTRUMENTASSESSMENTENGINE_BOND_H
#include "instrument.h"
#include "ZeroCoupon/zero_coupon_curve.h"
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

template <class T>
class Bond: public Instrument{

    public:
        Bond(std::string type, double nominal, ZerocouponCurve<T> &zcc, double interesFijoAnual): Instrument(type) {
            this->zcc=&zcc;
            this->nominal=nominal;
            this->fechaPresente=fechaPresente;
            this->fechaFinal=fechaFinal;
            this->interesFijoAnual = interesFijoAnual;
        }
        ~Bond(){}
        void pricer(){
            auto maturity_gap = this->zcc->getMaturityGap();
            std::vector<ZeroCoupon> zcv = this->zcc->getVectorZeroCoupon();
            for(int i = 0; i< zcv.size(); i++){
                double c = nominal * this->interesFijoAnual * maturity_gap;
                if(i == zcv.size() - 1){
                    c+=nominal;
                }
                zcv[i].pricer(c);
                this->prices.push_back(zcv[i].getPrice());
                this->pv += zcv[i].getPrice();
            }
        }
        double getPresentValue(){
            return this->pv;
        }
        /*vector<std::tm> getZeroCouponCurve(){
            vector<std::tm> fechasPagoZeroCoupon = this->zcc->getFechasPagoZeroCoupon();
            return fechasPagoZeroCoupon;

        }*/
        vector<double> getPrices(){
            return this->prices;
        }
    private:
        double nominal;
        tm fechaPresente;
        tm fechaFinal;
        ZerocouponCurve<T> *zcc;
        vector<double> prices;
        double pv;
        double interesFijoAnual;

};


#endif //INSTRUMENTASSESSMENTENGINE_BOND_H
