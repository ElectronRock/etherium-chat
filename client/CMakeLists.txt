cmake_minimum_required(VERSION 3.15)

project(client)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


file(GLOB CLI_HEADERS
        *.h
        ${CMAKE_SOURCE_DIR}/proto/*.h
)

file(GLOB CLI_SOURSES
        *.cpp
        ${CMAKE_SOURCE_DIR}/proto/*.cc
)

add_executable(client ${CLI_HEADERS} ${CLI_SOURSES})
target_include_directories(client PRIVATE ${CMAKE_SOURCE_DIR})

target_link_libraries(client grpc++)
