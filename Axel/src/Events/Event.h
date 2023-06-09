#ifndef EVENT_H_
#define EVENT_H_

#include <string>
#include <functional>

#define BIT(x) 1<<x

namespace Axel {
    
    enum class EventType
    {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum EventCategory 
    {
        None = 0,
        EventCategoryApplication = BIT(0),
        EventCategoryInput = BIT(1),
        EventCategoryKeyboard = BIT(2),
        EventCategoryMouse = BIT(3),
        EventCategoryMouseButton = BIT(4)
    };

#define EVENT_CLASS_TYPE(type) \
    static EventType StaticType() { return EventType::type; }\
    EventType GetEventType() const override { return StaticType(); }\
    const char* Name() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int CategoryFlags() const override { return category; }

    class Event
    {
        friend class EventDispatcher;
    public:
        virtual EventType GetEventType() const = 0;
        virtual const char* Name() const = 0;
        virtual int CategoryFlags() const = 0;
        virtual std::string ToString() const { return Name(); }

        inline bool IsInCategory(EventCategory category)
        {
            return CategoryFlags() & category;
        }

    protected:
     bool m_Handled = false;
    };

    class EventDispatcher
    {
        template<typename T>
        using EventFn = std::function<bool(T&)>;

    public:
        EventDispatcher(Event& event) : m_Event(event) {}

        template<typename T>
        bool Dispatch(EventFn<T> func)
        {
            if(m_Event.GetEventType() == T::StaticType())
            {
                m_Event.m_Handled = func(*(T*)&m_Event);
                return true;
            }
            return false;
        }
    private:
        Event& m_Event;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.ToString();
    }

}
#endif // EVENT_H_