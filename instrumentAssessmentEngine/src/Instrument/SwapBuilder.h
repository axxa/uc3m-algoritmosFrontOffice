//
// Created by axxa on 11/4/20.
//

#ifndef INSTRUMENTASSESSMENTENGINE_SWAPBUILDER_H
#define INSTRUMENTASSESSMENTENGINE_SWAPBUILDER_H

#include <Factory.h>

class SwapBuilder
{
public:
    static std::unique_ptr<IPricer> build (const InstrumentDescription& instrument);
    static InstrumentDescription::Type getId ();
};

#endif //INSTRUMENTASSESSMENTENGINE_SWAPBUILDER_H
