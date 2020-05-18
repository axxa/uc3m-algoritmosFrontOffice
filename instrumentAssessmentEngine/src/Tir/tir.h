
#ifndef INSTRUMENTASSESSMENTENGINE_TIR_H
#define INSTRUMENTASSESSMENTENGINE_TIR_H

#include <cmath>
#include "cuponPayment.h"
#include <vector>
#include <iostream>

using namespace  std;
template <class T>
class Tir
{
    private:
        vector<cuponPayment> payment;
        double marketValue;
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
            for(int i = 0; i<payment.size(); i++)
            {
                ret = ret + payment[i].getCouponAmount() * exp(-interest* payment[i].getDateInYears());
            }
            ret = ret - marketValue;
            return ret;
        }
        void addCupon(double years, double cupon){
            payment.push_back(cuponPayment(years,cupon));
        }
        void setMarketValue(double value){
            marketValue = value;
        }
        double function_x_prima(double point){
            double diferential = 0.1;
            return ((function_x(point + diferential) - function_x(point)) / diferential);
        }
};

#endif //INSTRUMENTASSESSMENTENGINE_TIR_H
