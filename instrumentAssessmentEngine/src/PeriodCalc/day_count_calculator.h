//
// Created by axxa on 11/4/20.
//

#ifndef INSTRUMENTASSESSMENTENGINE_DAYCOUNTCALCULATOR_H
#define INSTRUMENTASSESSMENTENGINE_DAYCOUNTCALCULATOR_H

#include <string>
#include <ctime>

using namespace std;
class DayCountCalculator
{
public:
    static tm make_date(const std::string & date){
        int day = std::stoi(date.substr(0,2));
        int month = std::stoi(date.substr(3,5));
        int year = std::stoi(date.substr(6,10)) - 1900;
        struct std::tm a = {0,0,0,day,month,year};
        return a;
    };

};
#endif //INSTRUMENTASSESSMENTENGINE_DAYCOUNTCALCULATOR_H
