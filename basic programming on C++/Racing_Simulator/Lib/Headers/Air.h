#pragma once
#include "Transport.h"

class Air : public Transport {
protected:
    double coef_dist;
public:
    void calc_time() override;
};
