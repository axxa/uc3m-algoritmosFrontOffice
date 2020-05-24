
#ifndef INSTRUMENTASSESSMENTENGINE_TIR_H
#define INSTRUMENTASSESSMENTENGINE_TIR_H

#include <cmath>
#include "cupon.h"
#include <vector>
#include <iostream>

using namespace  std;
template <class T>
class Tir
{
    private:
        vector<Cupon> pago;
        double valor;
    public:
        Tir(T convencion, vector<std::tm> fechasPagoZeroCoupon, std::tm fechaReset, vector<double> prices){
            for(int i = 0 ; i < prices.size(); i++){
                short yearCount = 0;

                if(i != 0){
                    yearCount = convencion.compute_daycount_by_convention(fechaReset,fechasPagoZeroCoupon[i]);
                    yearCount /= short(convencion.dias_anio());
                }

                addCupon(yearCount, prices[i]);
            }
        };
        ~Tir(){}
        double computeTir(double startPoint, int iterations){
            double x = startPoint;
            for(int i = 0; i<iterations; i++)
            {
                x = x - ( function_x(x) / function_x_prima(x));
            }
            return x;
        }
        double function_x(double interest){
            double ret = 0;
            for(int i = 0; i<pago.size(); i++)
            {
                ret = ret + pago[i].getValue() * exp(-interest* pago[i].getYearCount());
            }
            ret = ret - valor;
            return ret;
        }
        void addCupon(double years, double cupon){
            pago.push_back(Cupon(years,cupon));
        }
        void setMarketValue(double value){
            valor = value;
        }
        double function_x_prima(double point){
            double diferential = 0.1;
            return ((function_x(point + diferential) - function_x(point)) / diferential);
        }
};

#endif //INSTRUMENTASSESSMENTENGINE_TIR_H
