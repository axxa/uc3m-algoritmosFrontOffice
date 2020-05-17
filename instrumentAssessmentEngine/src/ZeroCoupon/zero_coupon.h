//
// Created by axxa on 3/5/20.
//

#ifndef INSTRUMENTASSESSMENTENGINE_ZERO_COUPON_H
#define INSTRUMENTASSESSMENTENGINE_ZERO_COUPON_H

#include <ctime>
#include <iostream>
#include <math.h>

#include "PeriodCalc/Actual_360.h"

using namespace std;

class ZeroCoupon
{
    private:
        std::tm fechaPago;
        double interest;
        double maturity;
        double price;
        double v_price;
    public:
        ZeroCoupon( double maturity, double interest,std::tm fechaPago){
            this->maturity = maturity;
            this->interest = interest;
            this->fechaPago = fechaPago;
            this->v_price = 0;
        };
        void pricer(double c){
            auto df = exp((-1) * interest * maturity);
            this->price = c * df;
            cout<< "coupon = C * DF :: C=" << c << " DF= exp(-" << interest << "*" << maturity<<")= "
            << this->price <<"\n";
        }
        void v_pricer(double c, int periodos_anio, double interestRateBefore, int actualPeriod){
            auto df = exp((-1) * interest * maturity);
            double RF = (this->interest*actualPeriod - interestRateBefore*(actualPeriod-1));
            double tipo_flotante = (periodos_anio * (exp(RF/periodos_anio) - 1));
            this->v_price = c * tipo_flotante;
            //cout<<"flotante:\n";
            cout<<"tipo_flotante=" << tipo_flotante;
        }
        double getPrice(){
            return price;
        }
        double getVPrice(){
            return v_price;
        }
        std::tm getFechaPago(){
            return fechaPago;
        }
        double getInterest(){
            return this->interest;
        }

};


#endif //INSTRUMENTASSESSMENTENGINE_ZERO_COUPON_H
