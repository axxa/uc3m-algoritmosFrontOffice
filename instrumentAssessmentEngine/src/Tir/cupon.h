

#ifndef INSTRUMENTASSESSMENTENGINE_CUPON_H
#define INSTRUMENTASSESSMENTENGINE_CUPON_H

class Cupon
{
    public:
        Cupon(double dateInYears, double value){
            this->yearCount = dateInYears;
            this->value = value;
        }
        double getYearCount(){
            return yearCount;
        }
        double getValue(){
            return value;
        }
    private:
        double yearCount;
        double value;
};
#endif //INSTRUMENTASSESSMENTENGINE_CUPON_H
