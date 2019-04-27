#include "WindowGLFW_GL.h"
#include "Event.h"

namespace Engine
{
    static bool s_GLFWInitiliazed = false;

    Window* Window::Create(const WindowProperties& props)
    {
        return new WindowGLFW_GL(props);
    }

    WindowGLFW_GL::WindowGLFW_GL(const WindowProperties& props)
    {
        Init(props);
    }

    void WindowGLFW_GL::Init(const WindowProperties &props)
    {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        if(!s_GLFWInitiliazed)
        {
            int success = glfwInit();
            E_CORE_ASSERT(success, "GLFW initiliazation failed");
            s_GLFWInitiliazed = true;
        }

        m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title, nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            glfwTerminate();
            throw "Error: OpenGL loader failure";
        }

        glfwSetWindowUserPointer(m_Window, &m_Data);

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
        {
            WindowCloseEvent event;
        });

        glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            switch (action)
            {
                case GLFW_PRESS:
                {

                }
                case GLFW_RELEASE:
                {

                }
                case GLFW_REPEAT:
                {

                }
            }
        });

    }

    WindowGLFW_GL::~WindowGLFW_GL()
    {
        Shutdown();
    }

    void WindowGLFW_GL::Shutdown()
    {
        glfwDestroyWindow(m_Window);
    }

    void WindowGLFW_GL::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void WindowGLFW_GL::SetVSync(bool enabled)
    {
        if(enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        m_Data.VSync = enabled;
    }

    bool WindowGLFW_GL::IsVSync() const
    {
        return m_Data.VSync;
    }

}



