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
        void v_pricer(double dcf, int periodos_anio, double interestRateBefore, int actualPeriod,
                double nominal, double interesFijo, double dayCountFractionAcumulado){
            double RF = (this->interest*actualPeriod - interestRateBefore*(actualPeriod-1));
            double tipo_flotante = (periodos_anio * (exp(RF/periodos_anio) - 1));
            double fixedFlow = interesFijo * dcf * nominal;
            double floatingFlow = dcf * tipo_flotante * nominal;
            double discountFactor = exp(-dayCountFractionAcumulado * interest);
            //cout << "discountFactor: " << "exp(-" << dcf << "*" << interest << "\n";
            cout << "floatingFlow "<< floatingFlow<< "::interesFlotante:" << tipo_flotante<<"\n";
                 //<< " dcf: "<< dcf << " nominal:" << nominal << " discountFactor: " << discountFactor <<"\n";
            this->v_price = (fixedFlow-floatingFlow) *  discountFactor;

            cout << "fixedFlow "<< fixedFlow<< "\n";
        }
        /*
         * void v_pricer(double dcf, int periodos_anio, double interestRateBefore, int actualPeriod,
                double nominal, double interesFijo, double dayCountFractionAcumulado){
            double RF = (this->interest*actualPeriod - interestRateBefore*(actualPeriod-1));
            double tipo_flotante = (periodos_anio * (exp(RF/periodos_anio) - 1));
            double fixedFlow = interesFijo * dcf * nominal;
            double floatingFlow = dcf * tipo_flotante * nominal;
            double discountFactor = exp(-dcf * interest);
            cout << "discountFactor: " << "exp(-" << dcf << "*" << interest << "\n";
            cout << "floatingFlow "<< floatingFlow<< "::interesFlotante:" << tipo_flotante
                 << " dcf: "<< dcf << " nominal:" << nominal << " discountFactor: " << discountFactor <<"\n";
            this->v_price = (fixedFlow-floatingFlow) *  discountFactor;

            cout << "fixedFlow "<< fixedFlow<< "\n";
        }
         * */
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
