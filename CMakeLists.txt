cmake_minimum_required(VERSION 2.6)

project("ScriptEngine")
set(SCRIPTENGINE_VERSION 1)
set(SCRIPTENGINE_VERSION_MINOR 0)
set(SCRIPTENGINE_VERSION_PATCH 0)
set(SCRIPTENGINE_AUTHOR "kmc7468")

file(GLOB SOURCES "./src/" "*.cc")
add_library(ScriptEngine SOURCES)

add_definitions(-std=c++1z -Wall -fmodules)