#pragma once

#include "Ground.h"

class Camel : public Ground {
public:
    Camel(int dist);
    void set_break_time() override;
};
