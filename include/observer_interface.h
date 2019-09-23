#pragma once

#include "enums.h"

struct observer
{
    virtual void on_event(const an_event &) noexcept = 0;
};
