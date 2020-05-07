//
// Created by axxa on 11/4/20.
//

#ifndef UC3M_ALGORITMOSFRONTOFFICE_ZEROCOUPONCURVE_H
#define UC3M_ALGORITMOSFRONTOFFICE_ZEROCOUPONCURVE_H

#include <iostream>
#include <vector>
#include <iomanip>
#include "PeriodCalc/Actual_360.h"
#include "zero_coupon.h"

class ZerocouponCurve {
    public:
        explicit ZerocouponCurve(Actual_360 convencion, vector<std::tm> fechasPagoZeroCoupon, vector<double> tiposZeroCoupon){
            cout<<"Constructor ZerocouponCurve";
            this->convencion= convencion;
            this->fechaInicial = fechasPagoZeroCoupon[0];
            this->fechasPagoZeroCoupon = fechasPagoZeroCoupon;
            calculate_maturity_gap();
            auto maturity_acum = maturityGap;
            for (auto element : tiposZeroCoupon) {
                addZeroCoupon(maturity_acum, element);
                maturity_acum += maturityGap;
            }
        };
        std::vector<ZeroCoupon> getVectorZeroCoupon(){
            return vectorZeroCoupon;
        }
        double getMaturityGap(){
            return maturityGap;
        }
    private:
        Actual_360 convencion;
        std::tm fechaInicial;
        std::vector<ZeroCoupon> vectorZeroCoupon;
        vector<std::tm> fechasPagoZeroCoupon;
        double maturityGap;
        void addZeroCoupon(double maturity, double interest)
        {
            ZeroCoupon zc(maturity, interest);
            this->vectorZeroCoupon.push_back( zc );
        }
        void calculate_maturity_gap(){
            auto periodos_pago = fechasPagoZeroCoupon.size() - 1;
            auto daycount = convencion.compute_daycount(fechasPagoZeroCoupon[0], fechasPagoZeroCoupon[periodos_pago]);
            auto total_maturity = daycount / convencion.dias_anio();
            maturityGap = total_maturity / periodos_pago;
        }


};

#endif //UC3M_ALGORITMOSFRONTOFFICE_ZEROCOUPONCURVE_H
