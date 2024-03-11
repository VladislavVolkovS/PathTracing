cmake_minimum_required(VERSION 3.8)

project(render)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
    nanobench
    GIT_REPOSITORY https://github.com/martinus/nanobench.git
    GIT_TAG v4.1.0
    GIT_SHALLOW TRUE)

FetchContent_MakeAvailable(nanobench)

add_executable(render "triangle.cpp" "sampler/sampler.cpp" "rndlb.cpp" "camera.cpp" "main.cpp" "sampler/halton.cpp" "sampler/scramble.cpp" "sampler/sobol.cpp")
target_include_directories(render PUBLIC externals/ externals/glm/)
target_link_libraries(render PRIVATE nanobench)
