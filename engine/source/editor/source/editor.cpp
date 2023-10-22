#include "editor.h"
#include "engine.h"


#include "editor_global_contex.h"


namespace zj
{
    zj_Editor::zj_Editor()
    {

    }

    zj_Editor::~zj_Editor(){};

    void zj_Editor::initialize(zj_Engine* engine_runtime)
    {
        g_is_editor_mode = true;
        m_engine_runtime = engine_runtime;

        EditorGlobalContexInitInfo init_info ;
        
    }
    void zj_Editor::clear()
    {

    }
    void zj_Editor::run()
    {
        
    }



}
