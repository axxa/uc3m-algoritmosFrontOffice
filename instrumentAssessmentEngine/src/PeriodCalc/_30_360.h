//
// Created by axxa on 11/4/20.
//

#ifndef INSTRUMENTASSESSMENTENGINE__30_360_H
#define INSTRUMENTASSESSMENTENGINE__30_360_H
#include "day_count_calculator.h"

using namespace std;

class _30_360 : public DayCountCalculator{
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
            int monthCount = (int) true_days/ dias_mes();
            if(monthCount>0){
                double residue =  (double) ((int) ((( (double) true_days / dias_mes()) - monthCount) * 10))/ 10;
                int aux = (int) (residue * dias_mes());
                days_by_convention = monthCount * dias_mes() + ( aux);
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
        static int dias_mes(){
            return 30;
        }
        static int dias_anio(){
            return 360;
        }

};
#endif //INSTRUMENTASSESSMENTENGINE__30_360_H
