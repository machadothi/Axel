#ifndef ENTRY_POINT_H_
#define ENTRY_POINT_H_

#include <iostream> // Removable

#include "Application.h"

extern Axel::Application* Axel::CreateApplication();

int main(int argc, char** argv) {

    std::cout << "Starting game engine." << std::endl;

    auto app = Axel::CreateApplication();

    app->Run();
    delete app;

    return 0;
}

#endif // ENTRY_POINT_H_