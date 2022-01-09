cmake_minimum_required(VERSION 3.15)
project(etherium)

include(FetchContent)
enable_testing()

FetchContent_Declare(
  gRPC
  GIT_REPOSITORY https://github.com/grpc/grpc
  GIT_TAG        v1.40.0
  )
set(FETCHCONTENT_QUIET OFF)
FetchContent_MakeAvailable(gRPC)

include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)
include("ext/hope.cmake")
include("ext/consolelib.cmake")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(client)
add_subdirectory(server)
