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
        std::tm fechaFinal;
        std::tm fechaInicial;
        double interest;
        double maturity;
        double price;
    public:
        ZeroCoupon( double maturity, double interest){
            cout<<"Constructor ZeroCoupon\n";
            this->maturity = maturity;
            this->interest = interest;
        };
        void pricer(double c){
            auto df = exp((-1) * interest * maturity);
            this->price = c * df;
        }
        double getPrice(){
            return price;
        }
};


#endif //INSTRUMENTASSESSMENTENGINE_ZERO_COUPON_H
