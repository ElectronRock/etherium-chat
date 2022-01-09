cmake_minimum_required(VERSION 3.15)

project(server)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SERVER_HEADERS
        *.h
        ${CMAKE_SOURCE_DIR}/proto/*.h
)

file(GLOB SERVER_SOURSES
        *.cpp
        ${CMAKE_SOURCE_DIR}/proto/*.cc
)

add_executable(server ${SERVER_HEADERS} ${SERVER_SOURSES})
target_include_directories(server PRIVATE ${CMAKE_SOURCE_DIR})

target_link_libraries(server grpc++)
