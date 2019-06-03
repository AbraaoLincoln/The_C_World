cmake_minimum_required(VERSION 3.5)
project(processador_cesar)

set( GCC_COMPILE_FLAGS "-Wall" )
set( GCC_COMPILE_FLAGS "-std=c++11" )

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(cesar ${SOURCES})
