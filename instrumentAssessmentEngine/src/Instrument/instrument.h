//
// Created by axxa on 11/4/20.
//

#ifndef INSTRUMENTASSESSMENTENGINE_INSTRUMENT_H
#define INSTRUMENTASSESSMENTENGINE_INSTRUMENT_H


#include <iostream>

class Instrument {
    public:
    std::string type;

    void buildInstrument( std::string type, ...);
};


#endif //INSTRUMENTASSESSMENTENGINE_INSTRUMENT_H
