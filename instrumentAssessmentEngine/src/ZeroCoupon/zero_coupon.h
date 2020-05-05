//
// Created by axxa on 3/5/20.
//

#ifndef INSTRUMENTASSESSMENTENGINE_ZERO_COUPON_H
#define INSTRUMENTASSESSMENTENGINE_ZERO_COUPON_H

#include <ctime>
#include <iostream>
#include "PeriodCalc/Actual_360.h"
using namespace std;

class ZeroCoupon
{
    private:
        double yearCount;
        double forward;
        std::tm fechaFinal;
        double interesAnual;
    public:
        ZeroCoupon( double yearCount, std::tm fechaFinal, double interest){
            cout<<"Constructor ZeroCoupon\n";
            this->fechaFinal = fechaFinal;
            this->interesAnual = interest;
            this->yearCount = yearCount;
        };
        void setForward(double timeInYearsBefore, double interestRateBefore, double numOfPeriodsPerYear, int actualPeriod);
        double getInterest();
        double getForward();
        double getTime();
};


#endif //INSTRUMENTASSESSMENTENGINE_ZERO_COUPON_H
