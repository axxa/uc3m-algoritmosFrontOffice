//
// Created by axxa on 3/5/20.
//

#ifndef INSTRUMENTASSESSMENTENGINE_UTILS_H
#define INSTRUMENTASSESSMENTENGINE_UTILS_H

#include <ctime>
#include <vector>
#include <string>

using namespace std;

class utils {
    public:
        utils(short n){}
        std::tm stringToTm(string string_date)
        {
            int day = std::stoi(string_date.substr(0,2));
            int month = std::stoi(string_date.substr(3,5));
            int year = std::stoi(string_date.substr(6,10)) - 1900;
            struct std::tm a = {0,0,0,day,month,year}; /* June 24, 2004 */
            return a;
        }
        vector<std::string> splitByDelimiter(std::string cadena, std::string delimiter){
            size_t pos = 0;
            std::string token;
            vector<std::string> splitted_;
            cadena = cadena + delimiter + " ";
            while ((pos = cadena.find(delimiter)) != std::string::npos) {
                token = cadena.substr(0, pos);
                splitted_.push_back(token);
                cadena.erase(0, pos + delimiter.length());
            }
            return splitted_;
        }

        vector<double> strVecToDoubleVec(vector<std::string> strVector){
            std::string::size_type sz;
            vector<double> doubleVector;
            for(auto element: strVector)
                doubleVector.push_back(std::stod (element,&sz));
            return doubleVector;
        }

        void showTimeSeries(vector<double> xVals, vector<double> yVals){
            // Output
            #define SP << fixed << setw( 15 ) << setprecision( 6 ) <<
            #define NL << '\n'
            cout << "\nInterpolated data:\n";
            for ( int i = 0; i < xVals.size(); i++ ) cout SP xVals[i] SP yVals[i] NL;
            cout << endl;
        }

};


#endif //INSTRUMENTASSESSMENTENGINE_UTILS_H
