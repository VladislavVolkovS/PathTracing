cmake_minimum_required(VERSION 3.8)

project(render)
set(CMAKE_CXX_STANDARD 17)

add_executable(render "triangle.cpp" "sampler/sampler.cpp" "rndlb.cpp" "camera.cpp" "main.cpp" "sampler/halton.cpp" "sampler/scramble.cpp" "sampler/sobol.cpp")
target_include_directories(render PUBLIC externals/ externals/glm/)
