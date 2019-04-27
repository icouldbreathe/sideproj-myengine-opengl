#ifndef APPLICATION_H
#define APPLICATION_H
#include "coreh.h"
#include "window.h"
#include "Event.h"

namespace Engine
{
    class Application {
    public:
        Application();

        std::unique_ptr<Window> m_Window;
        bool m_Running = false;

        void Run();
        void Shutdown();


        virtual void OnUpdate() = 0;
        virtual void OnEvent(Event& e);




        virtual ~Application();
    private:
        void InitWindow();
        void MainLoop();
        void Cleanup();
        bool OnWindowClose();
    };
}



#endif // APPLICATION_H
