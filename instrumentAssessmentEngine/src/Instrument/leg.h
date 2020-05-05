//
// Created by axxa on 11/4/20.
//

#ifndef INSTRUMENTASSESSMENTENGINE_LEG_H
#define INSTRUMENTASSESSMENTENGINE_LEG_H

//#include "day_count_calculator.h"

class leg {
    public:
        leg(double nominal,double interes, double interesFlotante, int anioActualDePago, int anioUltimoPago);
    private:
        double nominal;
        double interes;
        double interesFlotante;
        double anioActualDePago;
        double anioUltimoPago;
};


#endif //INSTRUMENTASSESSMENTENGINE_LEG_H
