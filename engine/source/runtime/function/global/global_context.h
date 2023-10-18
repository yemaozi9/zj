#pragma once
#include <memory>
#include <string>

namespace zj
{
    class WindowSystem;

    class RuntimeGlobalContext
    {
    public:
        //create all global systems and initialize these systems
        void startSystems(const std::string& config_file_path);
        //destory all global system
        void shutdownSystems();
    public:
        std::shared_ptr<WindowSystem>   m_window_system;

    };
    
    extern RuntimeGlobalContext g_runtime_global_context;
}