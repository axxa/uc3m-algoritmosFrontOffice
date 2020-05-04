//
// Created by axxa on 11/4/20.
//

#ifndef INSTRUMENTASSESSMENTENGINE_INSTRUMENT_H
#define INSTRUMENTASSESSMENTENGINE_INSTRUMENT_H


#include <iostream>

#include "instrument_description.cpp"

class Instrument {
    public:
        Instrument(std::string type);
    private:
        InstrumentDescription *instrumentDescription;

};


#endif //INSTRUMENTASSESSMENTENGINE_INSTRUMENT_H
