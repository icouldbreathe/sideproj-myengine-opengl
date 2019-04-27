#ifndef WINDOWGLFW_GL_H
#define WINDOWGLFW_GL_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "coreh.h"
#include <iostream>
#include "window.h"

namespace Engine
{
    class WindowGLFW_GL : public Window
    {
    public:
        WindowGLFW_GL(const WindowProperties& props);
        virtual ~WindowGLFW_GL();

        void OnUpdate() override;

        inline uint32_t GetWidth() const override { return m_Data.Width; }
        inline uint32_t GetHeight() const override { return m_Data.Height; }

        void SetVSync(bool enabled) override;
        bool IsVSync() const override;
    private:
        virtual void Init(const WindowProperties& props);
        virtual void Shutdown();
    private:
        GLFWwindow* m_Window;

        struct WindowData
        {
            const char* Title;
            unsigned int Width, Height;
            bool VSync;
        };

        WindowData m_Data;
    };
}



#endif // WINDOWGLFW_H
