#include "Axel.h"

class SandApp : public Axel::Application
{
private:
    /* data */
public:
    SandApp()
    {

    }
    ~SandApp()
    {

    }
};


Axel::Application* Axel::CreateApplication()
{
    return new SandApp();
}