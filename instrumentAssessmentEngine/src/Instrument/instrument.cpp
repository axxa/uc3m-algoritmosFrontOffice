//
// Created by axxa on 11/4/20.
//
#include <iostream>
#include "instrument.h"

Instrument::Instrument(int type)
{
    std::cout<<"aca instrument";
    if (type == 1)
    {
        this->instrumentDescription = new InstrumentDescription(InstrumentDescription::swap);
    }
    else if (type == 2)
    {
        this->instrumentDescription = new InstrumentDescription(InstrumentDescription::bond);
    }
}