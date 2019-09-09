#include <iostream>
#include "entt/src/entt/entt.hpp"

struct an_event
{};

struct listener
{
    void receive(const an_event &e, int value)
    { std::cout << "Hello " << value << " an_event" << std::endl; }
};

int main()
{
    // define a general purpose dispatcher that works with naked pointers
    entt::dispatcher<int> dispatcher{};

    listener listener;
    dispatcher.sink<an_event>().connect<&listener::receive>(&listener);
    dispatcher.trigger<an_event>(42);
    dispatcher.enqueue<an_event>();
    dispatcher.enqueue<an_event>();
    dispatcher.enqueue<an_event>();
    dispatcher.update<an_event>(1);
    dispatcher.sink<an_event>().disconnect<&listener::receive>(&listener);

    return 0;
}