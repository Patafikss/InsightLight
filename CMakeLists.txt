cmake_minimum_required(VERSION 2.8)

project(InsightLight)

set (glm "" CACHE PATH "embree include path")
set (EMBREE_LIB_PATH "" CACHE PATH "embree library path")

file(GLOB_RECURSE SRC_LIST "/*.cpp" )

file(GLOB_RECURSE INCLUDE_LIST "include/*.h" "include/*.hpp")

add_executable(${PROJECT_NAME} "/src/main.cpp" SRC_LIST)
