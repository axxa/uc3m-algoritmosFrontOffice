//
// Created by axxa on 11/4/20.
//

#ifndef INSTRUMENTASSESSMENTENGINE_ACTUAL_360_H
#define INSTRUMENTASSESSMENTENGINE_ACTUAL_360_H
#include "day_count_calculator.h"
using namespace std;

class Actual_360 : public DayCountCalculator{
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

    template<class DATE>
    double operator () (const DATE& start, const DATE& end) const
    {
        return compute_daycount(start, end)/ 360.0;
    }
    short dias_anio(){
        return 360;
    }

};

#endif //INSTRUMENTASSESSMENTENGINE_ACTUAL_360_H
