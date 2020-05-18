

#ifndef INSTRUMENTASSESSMENTENGINE_CUPONPAYMENT_H
#define INSTRUMENTASSESSMENTENGINE_CUPONPAYMENT_H

class cuponPayment
{
    public:
        cuponPayment(double dateInYears, double couponAmount){
            this->dateInYears = dateInYears;
            this->couponAmount = couponAmount;
        }
        double getDateInYears(){
            return dateInYears;
        }
        double getCouponAmount(){
            return couponAmount;
        }
    private:
        double dateInYears;
        double couponAmount;
};
#endif //INSTRUMENTASSESSMENTENGINE_CUPONPAYMENT_H
