cmake_minimum_required(VERSION 3.10)

project(mwe_networking_client)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})

find_package(enet)
find_package(spdlog)
target_link_libraries(${PROJECT_NAME} enet::enet spdlog::spdlog)
