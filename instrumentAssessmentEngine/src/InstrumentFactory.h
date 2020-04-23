//
// Created by axxa on 11/4/20.
//
#ifndef INSTRUMENTASSESSMENTENGINE_INSTRUMENTFACTORY_H
#define INSTRUMENTASSESSMENTENGINE_INSTRUMENTFACTORY_H

#include <Instrument/swap.h>
#include <Instrument/fixed_leg.h>
#include <Instrument/floating_leg.h>
#include <Instrument/bond.h>
#include <index.h>
#include <zero_coupon_curve.h>


using namespace std;


class InstrumentFactory {
    std::unique_ptr<Instrument> buildSwap( std::string type, ...);
    std::unique_ptr<Instrument> buildBond( std::string type, ...);
};


#endif //INSTRUMENTASSESSMENTENGINE_INSTRUMENTFACTORY_H
