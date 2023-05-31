#ifndef APPLICATION_EVENT_H_
#define APPLICATION_EVENT_H_

#include <sstream>

#include "Event.h"

namespace Axel {
    
    class WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(unsigned width, unsigned hight) : 
            m_Width(width), m_Height(hight) {}

        inline unsigned Width() const { return m_Width; }
        inline unsigned Height() const { return m_Height; }

        std::string ToString() const override
        {
            std::stringstream ss;

            ss << "WindowResizeEvent: " << m_Width << ", " 
                << m_Height << ")";

            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)

    private:
        unsigned m_Width, m_Height;
    };

    class WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() {}

        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

}

#endif // APPLICATION_EVENT_H_