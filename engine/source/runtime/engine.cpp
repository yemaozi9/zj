#include "engine.h"
#include <memory>
#include <iostream>
#include "window_system.h"
#include "function/global/global_context.h"
namespace zj
{
    bool                            g_is_editor_mode{ false };
    std::unordered_set<std::string> g_editor_tick_component_types{};

    void zj_Engine::startEngine(const std::string& config_file_path)
    {
        std::cout << "init" << std::endl;
        g_runtime_global_context.startSystems(config_file_path);
    }

    void zj_Engine::shutdownEngine()
    {
        g_runtime_global_context.shutdownSystems();
    }

    void zj_Engine::initialize() {}
    void zj_Engine::clear() {}

    void zj_Engine::run()
    {
        std::shared_ptr<WindowSystem> window_system = g_runtime_global_context.m_window_system;
        std::cout << "run" << std::endl;
        while (!window_system->shouldClose())
        {
            const float delta_time = calculateDeltaTime();
            tickOneFrame(delta_time);
            
            window_system->setBlackColor();
            window_system->processInput();
            window_system->pollEvents();
            window_system->SwapBuffers();
            
        }
    }
    float zj_Engine::calculateDeltaTime()
    {
        float delta_time;
        {
            using namespace std::chrono;
            steady_clock::time_point tick_time_point = steady_clock::now();
            duration<float>time_span = duration_cast<duration<float>>(tick_time_point - m_last_tick_time_point);
            delta_time = time_span.count();
            m_last_tick_time_point = tick_time_point;
        }
        return delta_time;
    }
    void zj_Engine::tickOneFrame(float delta_time)
    {
        logicalTick(delta_time);
        calculateFPS(delta_time);
        rendererTick(delta_time);

    }

    void zj_Engine::logicalTick(float delta_time)
    {

    }
    bool zj_Engine::rendererTick(float delta_time)
    {
        return true;
    }
    const float zj_Engine::s_fps_alpha = 1.f / 100;
    void zj_Engine::calculateFPS(float delta_time)
    {
        m_frame_count++;
        if (m_frame_count == 1)
        {
            m_average_duration = delta_time;
        }
        else
        {
            m_average_duration = m_average_duration * (1 - s_fps_alpha) + delta_time * s_fps_alpha;

        }
        m_fps = static_cast<int>(1.f / m_average_duration);
    }
}
