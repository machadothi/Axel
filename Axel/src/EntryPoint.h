#ifndef ENTRY_POINT_H_
#define ENTRY_POINT_H_

#include "Application.h"

extern Axel::Application* Axel::CreateApplication();

int main(int argc, char** argv) {

    Axel::Log::Init();
    AX_CORE_WARN("Starting game engine.");
    AX_INFO("Welcome. argc: {0}, argv{1}: ", argc, argv[0]);

    auto app = Axel::CreateApplication();

    app->Run();
    delete app;

    return 0;
}

#endif // ENTRY_POINT_H_