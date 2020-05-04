//
// Created by axxa on 11/4/20.
//

#ifndef INSTRUMENTASSESSMENTENGINE_BOND_H
#define INSTRUMENTASSESSMENTENGINE_BOND_H
#include "instrument.h"
#include <iostream>

class Bond: public Instrument{

    public:
        explicit Bond( std::string type);
    private:
        double capitalInicial;
        int zeroCoupon;

};


#endif //INSTRUMENTASSESSMENTENGINE_BOND_H
