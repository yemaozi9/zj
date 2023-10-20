#include"window_system.h"


namespace zj
{
    WindowSystem::~WindowSystem()
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }
    void WindowSystem::initialize(WindowCreateInfo create_info)
    {
        if (!glfwInit())
        {
            std::cout << "failed to initialize GLFW" << std::endl;
            return;
        }
        m_width = create_info.width;
        m_height = create_info.height;

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_window = glfwCreateWindow(create_info.width, create_info.height, create_info.title, nullptr, nullptr);
        if (!m_window)
        {
            std::cout << "failed to create window" << std::endl;
            glfwTerminate();
            return;
        }
        glfwMakeContextCurrent(m_window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return ;
        }
        glViewport(0, 0, create_info.width, create_info.height);

        
        
    }
    void WindowSystem::pollEvents()const { glfwPollEvents(); }
    bool WindowSystem::shouldClose()const { return glfwWindowShouldClose(m_window); }
    void WindowSystem::setTitle(const char* title) { glfwSetWindowTitle(m_window, title); }
    GLFWwindow* WindowSystem::getWindow()const { return m_window; }
    std::array<int, 2>WindowSystem::getWindowSize()const { return std::array<int, 2>({ m_width,m_height }); }
    void WindowSystem::SwapBuffers()const { glfwSwapBuffers(m_window); }
    void WindowSystem::setBlackColor(){
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
    void WindowSystem::processInput()
    {
        if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(m_window, true);
    }
}