//
// Created by axxa on 11/4/20.
//
#include "InstrumentFactory.h"
#include <iostream>
#include <memory>

std::unique_ptr<Instrument> InstrumentFactory::buildSwap( std::string type, ...)
{
    auto zerocouponCurve = make_unique<ZerocouponCurve>();
    auto index = make_unique<Index>(zerocouponCurve);
    auto fixed_leg = make_unique<FixedLeg>();
    auto floating_leg = make_unique<FloatingLeg>(*index);
    return make_unique<Swap>(fixed_leg, floating_leg);
}
std::unique_ptr<Instrument> InstrumentFactory::buildBond( std::string type, ...)
{

}