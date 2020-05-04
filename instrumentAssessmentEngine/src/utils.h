//
// Created by axxa on 3/5/20.
//

#ifndef INSTRUMENTASSESSMENTENGINE_UTILS_H
#define INSTRUMENTASSESSMENTENGINE_UTILS_H

#include <ctime>

class utils {
    public:
        std::tm stringToTm(string string_date)
        {
            int day = std::stoi(string_date.substr(0,2));
            int month = std::stoi(string_date.substr(3,5));
            int year = std::stoi(string_date.substr(6,10)) - 1900;
            struct std::tm a = {0,0,0,day,month,year}; /* June 24, 2004 */
            return a;
        }
};


#endif //INSTRUMENTASSESSMENTENGINE_UTILS_H
