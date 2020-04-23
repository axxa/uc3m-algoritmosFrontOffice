//
// Created by axxa on 11/4/20.
//

#ifndef INSTRUMENTASSESSMENTENGINE_SWAP_H
#define INSTRUMENTASSESSMENTENGINE_SWAP_H


#include <bits/unique_ptr.h>
#include "fixed_leg.h"
#include "floating_leg.h"
#include "instrument.h"

class Swap :public Instrument{

public:
    Swap(std::unique_ptr<FixedLeg> &, std::unique_ptr<FloatingLeg> &);
    //std::unique_ptr<ZerocouponCurve> & zcc
};


#endif //INSTRUMENTASSESSMENTENGINE_SWAP_H
