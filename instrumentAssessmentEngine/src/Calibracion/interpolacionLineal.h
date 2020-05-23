//
// Created by axxa on 23/5/20.
//

#ifndef INSTRUMENTASSESSMENTENGINE_INTERPOLACIONLINEAL_H
#define INSTRUMENTASSESSMENTENGINE_INTERPOLACIONLINEAL_H
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class InterpolacionLineal {
    public:
        InterpolacionLineal(vector<double> maturityVector, vector<double> interestVector){
            this->maturityVector = maturityVector;
            this->interestVector = interestVector;

            // Set up some points for interpolation in xVals
            const int NPTS = maturityVector.size();

            for ( int i = 1; i <= NPTS; i++ ) interpolatedMaturityVector.push_back( (double)i );

            // Interpolate
            for ( double x : interpolatedMaturityVector )
            {
                double y = interpolate( maturityVector, interestVector, x, true );
                interpolatedInterestVector.push_back( y );
            }

        }
        InterpolacionLineal(){}
        vector<double> getInterpolatedMaturityVector(){
            return this->interpolatedMaturityVector;
        }
        vector<double> getInterpolatedInterestVector(){
            return this->interpolatedInterestVector;
        }
    private:
        //======================================================================

        // Returns interpolated value at x from parallel arrays ( xData, yData )
        //   Assumes that xData has at least two elements, is sorted and is strictly monotonic increasing
        //   boolean argument extrapolate determines behaviour beyond ends of array (if needed)

        double interpolate( vector<double> &xData, vector<double> &yData, double x, bool extrapolate )
        {
            int size = xData.size();

            int i = 0;                                                                  // find left end of interval for interpolation
            if ( x >= xData[size - 2] )                                                 // special case: beyond right end
            {
                i = size - 2;
            }
            else
            {
                while ( x > xData[i+1] ) i++;
            }
            double xL = xData[i], yL = yData[i], xR = xData[i+1], yR = yData[i+1];      // points on either side (unless beyond ends)
            if ( !extrapolate )                                                         // if beyond ends of array and not extrapolating
            {
                if ( x < xL ) yR = yL;
                if ( x > xR ) yL = yR;
            }

            double dydx = ( yR - yL ) / ( xR - xL );                                    // gradient

            return yL + dydx * ( x - xL );                                              // linear interpolation
        }

        //======================================================================

        vector<double> maturityVector;
        vector<double> interestVector;

        vector<double> interpolatedMaturityVector;
        vector<double> interpolatedInterestVector;
};


#endif //INSTRUMENTASSESSMENTENGINE_INTERPOLACIONLINEAL_H
