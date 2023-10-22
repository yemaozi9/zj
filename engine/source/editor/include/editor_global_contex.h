#pragma once

namespace zj
{
    struct EditorGlobalContexInitInfo
    {
        class WindowSystem* window_system;
        class RenderSystem* render_system;
        class zj_Engine* engine_runtime;
    };

    class EditorGlobalContext
    {
    public:
        class WindowSystem* m_window_system{nullptr};
        class zj_Engine* m_engine_runtime{nullptr};

    public:
        void initialize(const EditorGlobalContexInitInfo& init_info);
        void clear();
    };

    extern EditorGlobalContext g_editor_global_context; 



}