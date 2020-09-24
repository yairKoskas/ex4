cmake_minimum_required(VERSION 3.0.0)
project(train VERSION 0.1.0)
set(CXX_STANDARD 17)

add_executable(train main.cpp
        MyParallelServer.cpp
        MySerialServer.cpp
        MyClientHandler.cpp
        State.cpp
        Matrix.cpp
        Graph.cpp
        MessageException.cpp)
link_libraries(train libmatrix)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
