//
// Created by axxa on 11/4/20.
//

#include <SwapBuilder.h>

namespace register_swap
{
    FactoryRegistrator<SwapBuilder> registration;
}
InstrumentDescription::Type SwapBuilder::getId ()
{
    return InstrumentDescription::Type::swap;
}
std::unique_ptr<IPricer> SwapBuilder::build (const InstrumentDescription& instrument)
{
//...
    std::unique_ptr<IPricer> swap;
    swap = std::make_unique<Swap>(receiver, payer, zerocouponCurve)
    return swap;
}