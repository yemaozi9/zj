#include <source/runtime/function/global/global_context.h>
#include <source/runtime/function/render/window_system.h>

namespace zj
{
    RuntimeGlobalContext g_runtime_global_context;
    void RuntimeGlobalContext::startSystems(const std::string& config_file_path)
    {
        m_window_system = std::make_shared<WindowSystem>();
        WindowCreateInfo window_create_info;
        m_window_system->initialize(window_create_info);
    
    }
    void RuntimeGlobalContext::shutdownSystems() 
    {
        m_window_system.reset();

    }


}