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

template <class T>
class ZerocouponCurve {
    public:
        explicit ZerocouponCurve(T convencion, vector<std::tm> fechasPagoZeroCoupon, vector<double> tiposZeroCoupon){
            this->convencion= convencion;
            this->fechaInicial = fechasPagoZeroCoupon[0];
            this->fechasPagoZeroCoupon = fechasPagoZeroCoupon;
            calculate_maturity_gap();
            auto maturity_acum = maturityGap;
            int i = 0;
            computeDayCountByPeriod();
            for (auto element : tiposZeroCoupon) {
                addZeroCoupon(maturity_acum, element, fechasPagoZeroCoupon[i]);
                maturity_acum += maturityGap;
                i++;
            }
        };
        std::vector<ZeroCoupon> getVectorZeroCoupon(){
            return this->vectorZeroCoupon;
        }
        std::vector<ZeroCoupon> *getZc() const {
            return this->vectorZeroCoupon;
        }
        double getMaturityGap(){
            return maturityGap;
        }
        T getConvencion(){
            return convencion;
        }
        vector<int> getDayCountByPeriod(){
            return dayCountByPeriod;
        }
        vector<std::tm> getFechasPagoZeroCoupon(){
            return fechasPagoZeroCoupon;
        }
    private:
        T convencion;
        std::tm fechaInicial;
        std::vector<ZeroCoupon> vectorZeroCoupon;
        vector<std::tm> fechasPagoZeroCoupon;
        vector<int> dayCountByPeriod;
        double maturityGap;
        void addZeroCoupon(double maturity, double interest, std::tm fechaPago)
        {
            ZeroCoupon zc(maturity, interest, fechaPago);
            this->vectorZeroCoupon.push_back( zc );
        }
        void calculate_maturity_gap(){
            auto periodos_pago = fechasPagoZeroCoupon.size() - 1;
            auto daycount = convencion.compute_daycount_by_convention(fechasPagoZeroCoupon[0], fechasPagoZeroCoupon[periodos_pago]);
            double total_maturity = (double) daycount / convencion.dias_anio();
            maturityGap = total_maturity / periodos_pago;
        }
        void computeDayCountByPeriod(){
            for(int i = 1 ; i <fechasPagoZeroCoupon.size(); i++){
                dayCountByPeriod.push_back(convencion.compute_daycount_by_convention(fechasPagoZeroCoupon[i-1],
                        fechasPagoZeroCoupon[i]));
            }
        }


};

#endif //UC3M_ALGORITMOSFRONTOFFICE_ZEROCOUPONCURVE_H
