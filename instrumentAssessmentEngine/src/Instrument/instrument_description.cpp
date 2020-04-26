//
// Created by axxa on 23/4/20.
//

struct InstrumentDescription
{
    enum Type {bond, swap};
    Type type;
    InstrumentDescription(Type type_):type(type_){}
    //LegDescription payer;
    //Let's assume receiver as the coupon bond definition
    //LegDescription receiver;
    //...
};