cmake_minimum_required(VERSION 3.10)

project(mwe_networking)

add_executable(mwe_networking main.cpp
        server.cpp
        client.cpp
        client.hpp
        server.hpp)

SET(ENET_STATIC ON CACHE BOOL "" FORCE)

add_subdirectory(external_libraries/enet)
include_directories(external_libraries/enet/include)

target_link_libraries(mwe_networking enet_static)