cmake_minimum_required(VERSION 3.0.0)
project(ex4.out VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror -Wnon-virtual-dtor -Wshadow)

add_executable(ex4.out TestBestFsAlgo.cpp BestFS.cpp Graph.cpp GraphSolver.cpp Matrix.cpp
MessageException.cpp MyParallelServer.cpp MySerialServer.cpp Solution.cpp State.cpp)

target_link_libraries(ex4.out -lpthread)
target_link_libraries(ex4.out -lmatrix.so)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
