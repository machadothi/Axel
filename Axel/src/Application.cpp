#include <iostream>

#include "Application.h"

#include "Events/KeyEvent.h"
#include "Log.h"

namespace Axel {
    Application::Application()
    {

    }

    Application::~Application()
    {

    }

    void Application::Run()
    {
        KeyReleasedEvent e(250);
        AX_CORE_WARN(e);

        while (true);
        
    }
}