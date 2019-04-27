#include "Engine.h"
#include <iostream>

#define E_DEBUG

class SandboxApplication : public Engine::Application
{
public:


    virtual void OnUpdate() override
    {

    }

    void OnEvent(Engine::Event& e) override
    {

    }

};

int main()
{
    SandboxApplication app;

    try
    {
        app.Run();
    } catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;

}
