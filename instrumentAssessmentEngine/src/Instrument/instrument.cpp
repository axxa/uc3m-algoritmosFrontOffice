//
// Created by axxa on 11/4/20.
//

#include "instrument.h"
#include <InstrumentFactory.h>

void Instrument::buildInstrument( std::string type, ...)
{
    InstrumentFactory myInstrumentFactory;
    std::unique_ptr<Instrument> instrument;
    if (type == "swap")
    {
        instrument = myInstrumentFactory.buildSwap(type);
    }
    else if (type == "bond")
    {
        instrument = myInstrumentFactory.createBond(...);
    }
}