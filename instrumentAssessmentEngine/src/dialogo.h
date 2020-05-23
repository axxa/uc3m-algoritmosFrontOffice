//
// Created by axxa on 23/5/20.
//

#ifndef INSTRUMENTASSESSMENTENGINE_DIALOGO_H
#define INSTRUMENTASSESSMENTENGINE_DIALOGO_H
#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <exception>
#include <Instrument/swap.h>
#include <Tir/tir.h>

#include "utils.h"
#include "PeriodCalc/Actual_actual.h"
#include "PeriodCalc/_30_360.h"
#include "PeriodCalc/Actual_360.h"
#include "Instrument/bond.h"

using namespace std;

class Dialogo {
    public:
       Dialogo(short n){
           seleccionarIntrumento();
       }

    private:
       void seleccionarIntrumento(){
           short seleccion=0;
           cout<<"Seleccione instrumento a valorar:\n";
           cout<<"1. Bono\n2. Swap\n";
           cin >>seleccion;
           if(seleccion == 1 )
               contruirBond();
           else if(seleccion == 2 )
               contruirSwap();
           else{
               cout<<"Seleccion incorrecta\n";
           }
       }

        void contruirBond(){
            utils u(1);
            std::string fechasPagoConcatenada, tiposZeroCouponConcat, fechaReset;
            vector<std::string> fechasZeroCouponString;
            vector<double> tiposZeroCoupon;
            double interesFijoAnual, nominal, pv;
            short opcionConvencion;
            double tirValue;

            cout<<"Ingrese la fecha inicial de pacto (formato: dd/mm/yyyy)"
                  " sin espacios:\n" << "Ejemplo: 31/06/2019\n";
            cin>>fechaReset;

            cout<<"Ingrese las fechas de pago Cero cupon (formato: dd/mm/yyyy), separadas por coma (,) "
                  "y sin espacios:\n"
                  "Ejemplo: 01/01/2019,31/06/2019,01/01/2020,31/06/2020\n";
            cin>>fechasPagoConcatenada;
            std::stringstream ss(fechasPagoConcatenada);
            fechasZeroCouponString = u.splitByDelimiter(fechasPagoConcatenada,",");

            cout<<"Ingrese los tipos cero cupon (ej: 0.05), separados por separados por coma (,)\n"
                  "Ejemplo: 0.05,0.058,0.064,0.068\n";
            cin>>tiposZeroCouponConcat;
            vector<std::string> tiposZeroCouponStringVec = u.splitByDelimiter(tiposZeroCouponConcat,",");
            tiposZeroCoupon = u.strVecToDoubleVec(tiposZeroCouponStringVec);

            cout<<"Ingrese el interes fijo anual (ej: 0.05):\n";
            cin >>interesFijoAnual;
            cout<<"Ingrese el interes nominal:\n";
            cin >>nominal;

            cout<<"Ingrese la convencion:\n";
            cout<<"1. 30/360\n2. Actual/360\n3. Actual/Actual\n";
            cin >>opcionConvencion;

            if(opcionConvencion == 1)
                pv  = bond30_360(fechaReset, fechasZeroCouponString,tiposZeroCoupon,
                                 nominal, interesFijoAnual,pv, tirValue);
            else if(opcionConvencion == 2)
                bondActual360(fechaReset, fechasZeroCouponString,tiposZeroCoupon,
                        nominal, interesFijoAnual,pv, tirValue);
            else if(opcionConvencion == 3)
                pv = bondActualActual(fechaReset, fechasZeroCouponString,tiposZeroCoupon,
                                      nominal, interesFijoAnual,pv, tirValue);
            else{
                cout<<"Opcion no valida";
                exit(0);
            }

            cout<< "El valor presente del bono es: " << pv <<"***\n";
            cout << "El valor de la TIR es: " << tirValue << endl;

        }

       void contruirSwap(){
           utils u(1);
           vector<std::string> fechasZeroCouponString;
           vector<double> tiposZeroCoupon;
           std::string tiposZeroCouponConcat, fechaReset, fechasPagoConcatenada;
           double tipoEnReset, interesFijoAnual, nominal, pv;
           short opcionConvencion;

           cout<<"Ingrese las fechas de pago Cero cupon (formato: dd/mm/yyyy), separadas por coma (,) "
                 "y sin espacios:\n"
                 "Ejemplo: 01/01/2019,31/06/2019,01/01/2020,31/06/2020\n";
           cin>>fechasPagoConcatenada;
           std::stringstream ss(fechasPagoConcatenada);
           fechasZeroCouponString = u.splitByDelimiter(fechasPagoConcatenada,",");

           cout<<"Ingrese la fecha inicial de pacto (formato: dd/mm/yyyy)"
                 " sin espacios:\n" << "Ejemplo: 31/06/2019\n";
           cin>>fechaReset;

           cout<<"Ingrese los tipos cero cupon (ej: 0.05), separados por separados por coma (,)\n"
                 "Ejemplo: 0.05,0.058,0.064,0.068\n";
           cin>>tiposZeroCouponConcat;
           vector<std::string> tiposZeroCouponStringVec = u.splitByDelimiter(tiposZeroCouponConcat,",");
           tiposZeroCoupon = u.strVecToDoubleVec(tiposZeroCouponStringVec);

           cout<<"Ingrese el interes fijo anual (ej: 0.05):\n";
           cin >>interesFijoAnual;
           cout<<"Ingrese el tipo en reset (ej: 0.05):\n";
           cin >>tipoEnReset;
           cout<<"Ingrese el interes nominal:\n";
           cin >>nominal;

           cout<<"Ingrese la convencion:\n";
           cout<<"1. 30/360\n2. Actual/360\n3. Actual/Actual\n";
           cin >>opcionConvencion;

           if(opcionConvencion == 1)
               pv  = swap30_360(fechasZeroCouponString, fechaReset, tiposZeroCoupon,
                                tipoEnReset, interesFijoAnual, nominal, pv);
           else if(opcionConvencion == 2)
               pv = swapActual360(fechasZeroCouponString, fechaReset, tiposZeroCoupon,
                                  tipoEnReset, interesFijoAnual, nominal, pv);
           else if(opcionConvencion == 3)
               pv = swapActualActual(fechasZeroCouponString, fechaReset, tiposZeroCoupon,
                                     tipoEnReset, interesFijoAnual, nominal, pv);
           else{
               cout<<"Opcion no valida";
               exit(0);
           }

           cout<< "El valor presente del bono es: " << pv <<"***\n\n";

       }




       //--------------------------------------------------------------------------------------------------
       void bondActual360(std::string fechaInicial, vector<std::string> fechasZeroCouponString,
                          vector<double> tiposZeroCoupon, double nominal, double interesFijoAnual,
                          double &pv, double &tirValue){
           auto convencion = Actual_360();
           //std::string fechainicial = fechasZeroCouponString[0];
           std::string fechafinal = fechasZeroCouponString[fechasZeroCouponString.size()-1];
           vector<std::tm> fechasPagoZeroCoupon;

           //-----------construir la curva cero cupon--------------------------------------------------------
           //auto convencion_360 = Actual_360();
           for (auto element : fechasZeroCouponString)
               fechasPagoZeroCoupon.push_back(convencion.make_date(element));
           ZerocouponCurve<Actual_360> zcc(convencion, fechasPagoZeroCoupon, tiposZeroCoupon);
           //------------------------------------------------------------------------------------------------

           Bond<Actual_360> bond("bond", nominal, zcc, interesFijoAnual);

           bond.pricer();


           std::tm fechaReset = convencion.make_date(fechaInicial);
           vector<double> prices = bond.getPrices();
           Tir<Actual_360> tir = Tir<Actual_360>(convencion, fechasPagoZeroCoupon,fechaReset,prices);
           tir.setMarketValue(bond.getPresentValue());

           tirValue = tir.computeTir(0, 10);
           pv = bond.getPresentValue();

           auto xVals = zcc.getCalibrada().getInterpolatedMaturityVector();
           auto yVals = zcc.getCalibrada().getInterpolatedInterestVector();
           utils u(1);
           u.showTimeSeries(xVals, yVals);
       }

        double bond30_360(std::string fechaInicial, vector<std::string> fechasZeroCouponString,
                          vector<double> tiposZeroCoupon, double nominal, double interesFijoAnual,
                          double &pv, double &tirValue){
            auto convencion = _30_360();
            std::string fechainicial = fechasZeroCouponString[0];
            std::string fechafinal = fechasZeroCouponString[fechasZeroCouponString.size()-1];
            vector<std::tm> fechasPagoZeroCoupon;

            //-----------construir la curva cero cupon--------------------------------------------------------
            //auto convencion_360 = Actual_360();
            for (auto element : fechasZeroCouponString)
                fechasPagoZeroCoupon.push_back(convencion.make_date(element));
            ZerocouponCurve<_30_360> zcc(convencion, fechasPagoZeroCoupon, tiposZeroCoupon);
            //------------------------------------------------------------------------------------------------

            Bond<_30_360> bond("bond", nominal, zcc, interesFijoAnual);

            bond.pricer();

            std::tm fechaReset = convencion.make_date(fechaInicial);
            vector<double> prices = bond.getPrices();
            Tir<_30_360> tir = Tir<_30_360>(convencion, fechasPagoZeroCoupon,fechaReset,prices);
            tir.setMarketValue(bond.getPresentValue());

            tirValue = tir.computeTir(0, 10);
            pv = bond.getPresentValue();

            auto xVals = zcc.getCalibrada().getInterpolatedMaturityVector();
            auto yVals = zcc.getCalibrada().getInterpolatedInterestVector();
            utils u(1);
            u.showTimeSeries(xVals, yVals);
        }

        double bondActualActual(std::string fechaInicial, vector<std::string> fechasZeroCouponString,
                                vector<double> tiposZeroCoupon, double nominal, double interesFijoAnual,
                                double &pv, double &tirValue){
            auto convencion = Actual_actual();
            std::string fechainicial = fechasZeroCouponString[0];
            std::string fechafinal = fechasZeroCouponString[fechasZeroCouponString.size()-1];
            vector<std::tm> fechasPagoZeroCoupon;

            //-----------construir la curva cero cupon--------------------------------------------------------
            //auto convencion_360 = Actual_360();
            for (auto element : fechasZeroCouponString)
                fechasPagoZeroCoupon.push_back(convencion.make_date(element));
            ZerocouponCurve<Actual_actual> zcc(convencion, fechasPagoZeroCoupon, tiposZeroCoupon);
            //------------------------------------------------------------------------------------------------

            Bond<Actual_actual> bond("bond", nominal, zcc, interesFijoAnual);

            bond.pricer();

            std::tm fechaReset = convencion.make_date(fechaInicial);
            vector<double> prices = bond.getPrices();
            Tir<Actual_actual> tir = Tir<Actual_actual>(convencion, fechasPagoZeroCoupon,fechaReset,prices);
            tir.setMarketValue(bond.getPresentValue());

            tirValue = tir.computeTir(0, 10);
            pv = bond.getPresentValue();

            auto xVals = zcc.getCalibrada().getInterpolatedMaturityVector();
            auto yVals = zcc.getCalibrada().getInterpolatedInterestVector();
            utils u(1);
            u.showTimeSeries(xVals, yVals);
        }

        double swapActual360(vector<std::string> fechasZeroCouponString, std::string fechainicial,
                vector<double> tiposZeroCoupon, double tipoEnReset,
                double interesFijoAnual, double nominal, double &pv){

            std::string fechafinal = fechasZeroCouponString[fechasZeroCouponString.size()-1];
            vector<std::tm> fechasPagoZeroCoupon;

            //-----------construir la curva cero cupon--------------------------------------------------------
            auto convencion = Actual_360();
            std::tm fechaReset = convencion.make_date(fechainicial);
            for (auto element : fechasZeroCouponString)
                fechasPagoZeroCoupon.push_back(convencion.make_date(element));
            ZerocouponCurve<Actual_360> zcc(convencion, fechasPagoZeroCoupon, tiposZeroCoupon);
            //------------------------------------------------------------------------------------------------

            Swap<Actual_360> swap("swap", nominal, zcc, interesFijoAnual, fechaReset, tipoEnReset);
            swap.pricer();

            pv = swap.getPresentValue();

            auto xVals = zcc.getCalibrada().getInterpolatedMaturityVector();
            auto yVals = zcc.getCalibrada().getInterpolatedInterestVector();
            utils u(1);
            u.showTimeSeries(xVals, yVals);
       }

    double swapActualActual(vector<std::string> fechasZeroCouponString, std::string fechaReset,
                         vector<double> tiposZeroCoupon, double tipoEnReset,
                         double interesFijoAnual, double nominal, double &pv){

        std::string fechafinal = fechasZeroCouponString[fechasZeroCouponString.size()-1];
        vector<std::tm> fechasPagoZeroCoupon;

        //-----------construir la curva cero cupon--------------------------------------------------------
        auto convencion = Actual_actual();
        std::tm fechainicial = convencion.make_date(fechaReset);
        for (auto element : fechasZeroCouponString)
            fechasPagoZeroCoupon.push_back(convencion.make_date(element));
        ZerocouponCurve<Actual_actual> zcc(convencion, fechasPagoZeroCoupon, tiposZeroCoupon);
        //------------------------------------------------------------------------------------------------

        Swap<Actual_actual> swap("swap", nominal, zcc, interesFijoAnual, fechainicial, tipoEnReset);
        swap.pricer();

        pv = swap.getPresentValue();

        auto xVals = zcc.getCalibrada().getInterpolatedMaturityVector();
        auto yVals = zcc.getCalibrada().getInterpolatedInterestVector();
        utils u(1);
        u.showTimeSeries(xVals, yVals);
    }

    double swap30_360(vector<std::string> fechasZeroCouponString, std::string fechaReset,
                            vector<double> tiposZeroCoupon, double tipoEnReset,
                            double interesFijoAnual, double nominal, double &pv){

        std::string fechafinal = fechasZeroCouponString[fechasZeroCouponString.size()-1];
        vector<std::tm> fechasPagoZeroCoupon;

        //-----------construir la curva cero cupon--------------------------------------------------------
        auto convencion = _30_360();
        std::tm fechainicial = convencion.make_date(fechaReset);
        for (auto element : fechasZeroCouponString)
            fechasPagoZeroCoupon.push_back(convencion.make_date(element));
        ZerocouponCurve<_30_360> zcc(convencion, fechasPagoZeroCoupon, tiposZeroCoupon);
        //------------------------------------------------------------------------------------------------

        Swap<_30_360> swap("swap", nominal, zcc, interesFijoAnual, fechainicial, tipoEnReset);
        swap.pricer();
        pv = swap.getPresentValue();

        auto xVals = zcc.getCalibrada().getInterpolatedMaturityVector();
        auto yVals = zcc.getCalibrada().getInterpolatedInterestVector();
        utils u(1);
        u.showTimeSeries(xVals, yVals);
    }
};


#endif //INSTRUMENTASSESSMENTENGINE_DIALOGO_H
