#include "editor_global_contex.h"
#include "window_system.h"

namespace zj
{
    EditorGlobalContext g_editor_global_context;
    void EditorGlobalContext::initialize(const EditorGlobalContexInitInfo& init_info)
    {
       g_editor_global_context.m_window_system = init_info.window_system;
       g_editor_global_context.m_engine_runtime = init_info.engine_runtime;

    }
    void EditorGlobalContext::clear()
    {
    

    }


}
