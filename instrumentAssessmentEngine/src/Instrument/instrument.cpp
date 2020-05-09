//
// Created by axxa on 11/4/20.
//
#include <iostream>
#include "instrument.h"

Instrument::Instrument(std::string type)
{
    if (type == "swap")
    {
        this->instrumentDescription = new InstrumentDescription(InstrumentDescription::swap);
    }
    else if (type == "bond")
    {
        this->instrumentDescription = new InstrumentDescription(InstrumentDescription::bond);
    }
}