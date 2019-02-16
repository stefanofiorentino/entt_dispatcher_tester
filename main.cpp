#include <iostream>
#include "entt/src/entt/entt.hpp"

int main()
{
    // define a general purpose dispatcher that works with naked pointers
    entt::dispatcher dispatcher{};

    struct an_event
    {
        int value;

        an_event() :
                value(-1)
        {};

        an_event(int value) :
                value(value)
        {};

    };
    struct another_event
    {
    };

    struct listener
    {
        void receive(const an_event &e)
        { std::cout << "Hello " << e.value << " an_event" << std::endl; }

        void method(const another_event &a)
        { std::cout << "Hello, another_event!" << std::endl; }
    };

    listener listener;
    dispatcher.sink<an_event>().connect<&listener::receive>(&listener);
    dispatcher.sink<another_event>().connect<&listener::method>(&listener);

    dispatcher.trigger<an_event>(42);
    dispatcher.trigger<another_event>();

    dispatcher.sink<an_event>().disconnect<&listener::receive>(&listener);
    dispatcher.sink<another_event>().disconnect<&listener::method>(&listener);

    return 0;
}