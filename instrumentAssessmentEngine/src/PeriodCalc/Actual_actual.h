//
// Created by axxa on 11/4/20.
//

#ifndef INSTRUMENTASSESSMENTENGINE_ACTUAL_ACTUAL_H
#define INSTRUMENTASSESSMENTENGINE_ACTUAL_ACTUAL_H

#include "day_count_calculator.h"
using namespace std;

class Actual_actual : public DayCountCalculator{
public:
    static short compute_daycount(const std::string & from, const std::string & to){
        std::tm a = make_date(from);
        std::tm b = make_date(to);
        std::time_t x = std::mktime(&a);
        std::time_t y = std::mktime(&b);
        return std::difftime(y, x) / (60 * 60 * 24);
    };

    static short compute_daycount(std::tm a, std::tm b){
        std::time_t x = std::mktime(&a);
        std::time_t y = std::mktime(&b);
        return std::difftime(y, x) / (60 * 60 * 24);
    };

    static short compute_daycount_by_convention(std::tm a, std::tm b){
        return compute_daycount(a,b);
    };

    template<class DATE>
    double operator () (const DATE& start, const DATE& end) const
    {
        return compute_daycount(start, end)/ 365.0;
    }
    static int dias_anio(){
        return 365;
    }

};

#endif //INSTRUMENTASSESSMENTENGINE_ACTUAL_ACTUAL_H
