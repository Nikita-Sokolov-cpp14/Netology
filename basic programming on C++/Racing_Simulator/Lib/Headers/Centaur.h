#pragma once

#include "Ground.h"

class Centaur : public Ground {
public:
    Centaur(int dist);
    void set_break_time() override;
};
