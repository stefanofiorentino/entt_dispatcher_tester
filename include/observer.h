#pragma once

#include "observer_interface.h"

struct observer_concrete : public observer
{
    EVENT_TYPE state{EVENT_TYPE::REJECT};

    void on_event(const an_event &) noexcept override
    {
        state = EVENT_TYPE::RESOLVE;
    }
};
