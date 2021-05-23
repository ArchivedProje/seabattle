cmake_minimum_required(VERSION 3.17)
project(seabattle)

set(CMAKE_CXX_STANDARD 20)

add_executable(demo main.cpp)

add_library(${PROJECT_NAME} STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/Printing.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/AI.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/Player.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/Controller.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/sources/Data.cpp
        )

target_include_directories(${PROJECT_NAME} PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:include>"
        )

target_link_libraries(demo ${PROJECT_NAME})
