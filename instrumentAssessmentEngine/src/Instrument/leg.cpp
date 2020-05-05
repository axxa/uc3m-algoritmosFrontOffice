//
// Created by axxa on 11/4/20.
//

#include "leg.h"

leg::leg(double nominal, double interes, double interesFlotante, int anioActualDePago, int anioUltimoPago) {
        this->nominal = nominal;
        this->interes = interes;
        this->interesFlotante = interesFlotante;
        this->anioActualDePago= anioActualDePago;
        this->anioUltimoPago = anioUltimoPago;
}
