#ifndef KEY_EVENT_H_
#define KEY_EVENT_H_

#include <sstream>

#include "Event.h"

namespace Axel {

    class KeyEvent : public Event
    {
    public:
        inline int KeyCode() const { return m_KeyCode; }

        EVENT_CLASS_CATEGORY( EventCategoryKeyboard | EventCategoryInput)

    protected:
        KeyEvent(int keycode) : m_KeyCode(keycode) {}

        int m_KeyCode;
    };

    class KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(int keycode, int repeatCount) : 
            KeyEvent(keycode), m_RepeatCount(repeatCount) {}

        std::string ToString() const override
        {
            std::stringstream ss;

            ss << "KeyPressedEvent: " << m_KeyCode << " (" 
                << m_RepeatCount << ")";

            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed);


    private:
        int m_RepeatCount;
    };

    class KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

        std::string ToString() const override
        {
            std::stringstream ss;

            ss << "KeyPressedEvent: " << m_KeyCode;

            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed);
    };
}

#endif // KEY_EVENT_H_