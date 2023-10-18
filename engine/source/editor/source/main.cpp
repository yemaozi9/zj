#include <filesystem>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <unordered_map>
#include "engine/source/runtime/engine.h"
int main(int argc,char**argv)
{
    std::filesystem::path executable_path(argv[0]);
    std::filesystem::path config_file_path = executable_path.parent_path() / "zj.ini";
    zj::zj_Engine *engine =new zj::zj_Engine();

    engine->startEngine(config_file_path.generic_string());
    engine->run();
    engine->shutdownEngine();
   
    return 0;

}