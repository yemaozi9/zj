#pragma once
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <array>
#include <iostream>
namespace zj
{
    struct WindowCreateInfo
    {
        int   width{ 1280 };
        int   height{ 720 };
        const char* title{ "zj_Engine" };
        bool    is_fullscreen{ false };
    };
    class WindowSystem
    {
    public:
        WindowSystem() = default;
        ~WindowSystem();
        void          initialize(WindowCreateInfo create_info);
        void          pollEvents()const;
        bool          shouldClose()const;
        void          setTitle(const char* title);
        void          setBlackColor();
        GLFWwindow*   getWindow()const;
        std::array<int, 2>getWindowSize()const;
        void          SwapBuffers()const;
        void          processInput();
    private:
        GLFWwindow* m_window{ nullptr };
        int         m_width{ 0 };
        int         m_height{ 0 };

    };
}