project(zj_Engine)
aux_source_directory(source SRC_sub)
add_executable zj(${SRC_sub})
include_directories(3rdparty configs)