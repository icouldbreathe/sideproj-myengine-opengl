#ifndef EVENT_H
#define EVENT_H

#include "coreh.h"
#include <queue>
#include <iostream>

namespace Engine
{

    enum class EventType
    {
        None = 0,
        WindowClose, WindowResize,
        KeyPressed, KeyReleased
    };

    class Event
    {
    public:
        bool Handled = false;
        virtual EventType GetEventType() const = 0;
    };

    class WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() {}
        virtual EventType GetEventType() const override
        {
            return EventType::WindowClose;
        }
    };

    class EventDispatcher
    {
        template<typename T>
        using EventFn = std::function<bool(T&)>;
    public:
        EventDispatcher(Event& event)
            : m_Event(event)
        {
        }

        template<typename T>
        bool Dispatch(EventFn<T> func)
        {
            m_Event.Handled = func(*(T*)&m_Event);
            return true;
        }
    private:
        Event& m_Event;
    };

}


#endif // EVENT_H
