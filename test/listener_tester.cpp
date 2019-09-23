#include <gtest/gtest.h>
#include <entt/signal/dispatcher.hpp>

#include "include/observer.h"

struct test_observer_concrete : public observer_concrete
{
    bool on_event_called{false};
    using parent = observer_concrete;

    void on_event(const an_event &to) noexcept final
    {
        parent::on_event(to);
        on_event_called = true;
    }
};

TEST(ObserverPattern, AuthorDemo)
{
    entt::dispatcher dispatcher;
    test_observer_concrete observer;

    dispatcher.sink<an_event>().connect<&test_observer_concrete::on_event>(observer);
    dispatcher.trigger<an_event>();
    dispatcher.sink<an_event>().disconnect<&test_observer_concrete::on_event>(observer);

    ASSERT_EQ(observer.state, EVENT_TYPE::RESOLVE);
    ASSERT_TRUE(observer.on_event_called);
    ASSERT_TRUE(dispatcher.sink<an_event>().empty());
}
