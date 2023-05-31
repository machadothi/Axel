#ifndef KEY_EVENT_H_
#define KEY_EVENT_H_

#include <sstream>

#include "Event.h"

namespace Axel {
    
    class MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y) {}

        inline float X() const { return m_MouseX; }
        inline float Y() const { return m_MouseY; }

        std::string ToString() const override
        {
            std::stringstream ss;

            ss << "MouseMovedEvent: " << m_MouseX << ", " 
                << m_MouseY << ")";

            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
        float m_MouseX, m_MouseY;
    };

    class MouseScrolledEvent : public Event
    {
    public:
        MouseScrolledEvent(float xOffset, float yOffset) : 
            m_XOffset(xOffset), m_YOffset(yOffset) {}

        inline float XOffset() const { return m_XOffset; }
        inline float YOffset() const { return m_YOffset; }

        std::string ToString() const override
        {
            std::stringstream ss;

            ss << "MouseScrolledEvent: " << m_XOffset << ", " 
                << m_YOffset << ")";

            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

    private:
        float m_XOffset, m_YOffset;
    };

    class MouseButtonEvent : public Event
    {
    public:
        inline int MouseButton() const { return m_Button;}

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    protected:
        MouseButtonEvent(int button) : m_Button(button) {}

        int m_Button;
    };

    class MouseButtonPressedEvent : public MouseButtonEvent
    {   
    public:
        MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;

            ss << "MousePressedEvent: " << m_Button;

            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class MouseButtonReleasedEvent : public MouseButtonEvent
    {   
    public:
        MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;

            ss << "MouseReleasedEvent: " << m_Button;

            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };
}

#endif // KEY_EVENT_H_