#ifndef APPLICATION_H_
#define APPLICATION_H_

namespace Axel {

    class Application {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    // To be defined in the CLIENT scope.
    Application* CreateApplication();

}


#endif // APPLICATION_H_