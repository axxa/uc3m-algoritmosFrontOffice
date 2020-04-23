//
// Created by axxa on 11/4/20.
//
#include <zero_coupon_curve.h>

#ifndef UC3M_ALGORITMOSFRONTOFFICE_INDEX_H
#define UC3M_ALGORITMOSFRONTOFFICE_INDEX_H


class Index {
    public:
        Index(std::unique_ptr<ZerocouponCurve> & zcc);
};


#endif //UC3M_ALGORITMOSFRONTOFFICE_INDEX_H
