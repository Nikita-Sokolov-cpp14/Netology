#pragma once

#include "Ground.h"

class BootsRover : public Ground {
public:
    BootsRover(int dist);
    void set_break_time() override;
};
