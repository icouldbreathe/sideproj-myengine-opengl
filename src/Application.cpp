#include "Application.h"

namespace Engine
{
    Application::Application()
    {
        m_Window = std::unique_ptr<Engine::Window>(Engine::Window::Create());
        m_Running = true;
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        MainLoop();
        Cleanup();
    }

    void Application::Shutdown()
    {
        m_Running = false;
        Cleanup();
    }

    void Application::OnEvent(Event& e)
    {

    }

    void Application::MainLoop()
    {
        while(m_Running)
        {


            m_Window->OnUpdate();
            OnUpdate();
        }
    }

    bool Application::OnWindowClose()
    {
        m_Running = false;
        return true;
    }

    void Application::Cleanup()
    {

    }
}

