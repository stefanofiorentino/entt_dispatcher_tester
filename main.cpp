#include <iostream>
#include "entt/src/entt/entt.hpp"

int main()
{
    // define a general purpose dispatcher that works with naked pointers
    entt::dispatcher dispatcher{};

    std::cout << "Hello, World!" << std::endl;
    return 0;
}