#pragma once

#include "Ground.h"

class CamelBoost : public Ground {
public:
    CamelBoost(int dist);
    void set_break_time() override;
};
