#pragma once

#include <memory>

namespace zj
{

    class EditorUI;
    class zj_Engine;

    class zj_Editor
    {
        friend class EditorUI;
    public:
        zj_Editor();
        virtual ~zj_Editor();

        void initialize(zj_Engine* engine_runtime);
        void clear();

        void run();
    protected:
        std::shared_ptr<EditorUI> m_editor_ui;
        zj_Engine* m_engine_runtime {nullptr};
    };


}