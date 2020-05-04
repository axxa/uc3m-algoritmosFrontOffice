//
// Created by axxa on 11/4/20.
//

#ifndef INSTRUMENTASSESSMENTENGINE_SWAP_H
#define INSTRUMENTASSESSMENTENGINE_SWAP_H


#include <memory>
#include "fixed_leg.h"
#include "floating_leg.h"
#include "instrument.h"

class Swap :public Instrument{

public:
    explicit Swap( std::string type);
    //std::unique_ptr<ZerocouponCurve> & zcc
};


#endif //INSTRUMENTASSESSMENTENGINE_SWAP_H
