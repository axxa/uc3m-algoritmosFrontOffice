//
// Created by axxa on 11/4/20.
//

#ifndef INSTRUMENTASSESSMENTENGINE_ACTUAL_360_H
#define INSTRUMENTASSESSMENTENGINE_ACTUAL_360_H
#include "day_count_calculator.h"
using namespace std;

//Actual/360: Consideramos el número real de días para los meses y para los años 360 días.
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

    static short compute_daycount_by_convention(std::tm a, std::tm b){
        auto true_days = compute_daycount(a,b);
        int days_by_convention = 0;
        int yearCount = (int) true_days/ dias_anio();
        if(yearCount>0){
            double residue =  (double) ((int) ((( (double) true_days / dias_anio()) - yearCount) * 10))/ 10;
            int aux = (int) (residue * dias_anio());
            days_by_convention = yearCount * dias_anio() + ( aux);
            days_by_convention += residue;
            return days_by_convention;
        }
        else{
            return true_days;
        }

    };

    template<class DATE>
    double operator () (const DATE& start, const DATE& end) const
    {
        return compute_daycount(start, end)/ 360.0;
    }
    static int dias_anio(){
        return 360;
    }

};

#endif //INSTRUMENTASSESSMENTENGINE_ACTUAL_360_H
