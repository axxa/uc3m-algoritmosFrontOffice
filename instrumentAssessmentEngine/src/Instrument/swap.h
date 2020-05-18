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
    Swap(std::string type, double nominal, ZerocouponCurve<T> &zcc, double interesFijoAnual,
            std::tm fechaPresente, double interesEnReset): Instrument(type) {
            this->zcc=&zcc;
            this->nominal=nominal;
            this->fechaPresente=fechaPresente;
            this->fechaFinal=fechaFinal;
            this->interesFijoAnual = interesFijoAnual;
            this->interesEnReset = interesEnReset;
    }
    void pricer(){
        auto maturity_gap = this->zcc->getMaturityGap();
        T convencion = this->zcc->getConvencion();
        double dayCountFraction = 0.0;
        double dayCountFractionAcumulado = 0.0;
        std::vector<ZeroCoupon> zcv = this->zcc->getVectorZeroCoupon();
        for(int i = 0; i< zcv.size(); i++){
            double c = nominal * this->interesFijoAnual * maturity_gap;
            if(i == zcv.size() - 1){
                c+=nominal;
            }
            //zcv[i].pricer(c);
            if(i>0){

                dayCountFraction = (1.000 * convencion
                        .compute_daycount_by_convention(zcv[i-1].getFechaPago(), zcv[i].getFechaPago()));
                dayCountFraction /= convencion.dias_anio() ;

                zcv[i].v_pricer(dayCountFraction,1/maturity_gap,
                        zcv[i-1].getInterest(),i+1, nominal, interesFijoAnual, dayCountFractionAcumulado);
                dayCountFractionAcumulado += dayCountFraction;
            }
            else{

                dayCountFraction = (1.000 * convencion
                        .compute_daycount_by_convention(fechaPresente, zcv[i].getFechaPago()));
                dayCountFraction /= convencion.dias_anio();

                zcv[i].v_pricer(dayCountFraction,
                        1/maturity_gap,interesEnReset,i+1, nominal, interesFijoAnual, dayCountFractionAcumulado);
                dayCountFractionAcumulado += dayCountFraction;
            }
            //this->pv += zcv[i].getPrice();
            this->pv += zcv[i].getVPrice();
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
        double interesEnReset;

};


#endif //INSTRUMENTASSESSMENTENGINE_SWAP_H
