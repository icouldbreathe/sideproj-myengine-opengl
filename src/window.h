#ifndef WINDOW_H
#define WINDOW_H

#include "coreh.h"
#include <iostream>

namespace Engine
{
    struct WindowProperties {
        uint32_t    Width;
        uint32_t    Height;
        const char* Title;

        WindowProperties(uint32_t width = 600, uint32_t height = 400, const char* title = "Engine Application")
            : Width(width)
            , Height(height)
            , Title(title)
        {
        }
    };

    class Window
    {
    protected:

    public:
        virtual ~Window() {}

        virtual void OnUpdate() = 0;

        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        virtual uint32_t GetWidth() const = 0;
        virtual uint32_t GetHeight() const = 0;

        static Window* Create(const WindowProperties& props = WindowProperties());

    };

}

#endif // WINDOW_H
