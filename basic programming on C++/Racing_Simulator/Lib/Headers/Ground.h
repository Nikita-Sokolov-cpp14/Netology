#pragma once
#include "Transport.h"

class Ground : public Transport {
protected:
    int driving_time;
    double break_time;
    int break_number = 0;
public:
    virtual void set_break_time();
    void calc_time() override;
};
