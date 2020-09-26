# cmake_minimum_required(VERSION 3.0.0)
# project(Server VERSION 0.1.0)

# include(CTest)
# enable_testing()
# find_package (Threads REQUIRED)
# add_compile_options(-Wall -Wextra -pedantic -Werror -Wnon-virtual-dtor -Wshadow)
# include_directories(${CMAKE_SOURCE_DIR}/matrix  ${CMAKE_SOURCE_DIR}/search_problem ${CMAKE_SOURCE_DIR}/command ${CMAKE_SOURCE_DIR}/server_side)
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
# link_directories(${CMAKE_SOURCE_DIR}/matrix  ${CMAKE_SOURCE_DIR}/search_problem ${CMAKE_SOURCE_DIR}/command ${CMAKE_SOURCE_DIR}/server_side)
# add_executable(ex4.out main.cpp
# AStar.cpp
# BestFS.cpp
# BFS.cpp
# DFS.cpp
# Graph.cpp
# GraphSolver.cpp
# Matrix.cpp
# MessageException.cpp
# MyClientHandler.cpp
# MyParallelServer.cpp
# MySerialServer.cpp
# Solution.cpp
# State.cpp
# )
# target_link_libraries(ex4.out matrix  ${CMAKE_THREAD_LIBS_INIT})
# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)


cmake_minimum_required(VERSION 3.0.0)
project(ex3 VERSION 0.1.0)

<<<<<<< HEAD
=======
include(CTest)
enable_testing()
find_package (Threads REQUIRED)
add_compile_options(-Wall -Wextra -pedantic -Werror -Wnon-virtual-dtor -Wshadow)
>>>>>>> 537709e809e8dd667d4d72380a3ef49c44a97eee
set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror -Wnon-virtual-dtor -Wshadow)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
<<<<<<< HEAD

# add the .cpp files of the project
add_executable(ex4.out TestAlgo.cpp
AStar.cpp
=======
add_executable(ex4.out main.cpp
>>>>>>> 537709e809e8dd667d4d72380a3ef49c44a97eee
BestFS.cpp
AStar.cpp
BFS.cpp
DFS.cpp
Graph.cpp
Matrix.cpp
MessageException.cpp
<<<<<<< HEAD
# MyClientHandler.cpp
# MyParallelServer.cpp
# MySerialServer.cpp
Solution.cpp
State.cpp)

# add the library
target_link_libraries(ex4.out matrix)

# add the folders of the .h files (to be able to include them)
# target_include_directories(ex3.out PUBLIC
#                             ${CMAKE_SOURCE_DIR}/bmp
#                             ${CMAKE_SOURCE_DIR}/cache
#                             ${CMAKE_SOURCE_DIR}/exceptions
#                             ${CMAKE_SOURCE_DIR}/hash
#                             ${CMAKE_SOURCE_DIR}/matrix
#                             ${CMAKE_SOURCE_DIR}/paths
#                             )

# make the cache directory
file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/cache)

# include the src directory
target_link_directories(ex4.out PUBLIC ${PROJECT_SOURCE_DIR})

=======
MyClientHandler.cpp
MyParallelServer.cpp
MySerialServer.cpp
Matrix.cpp)
target_link_directories(ex4.out PUBLIC ${PROJECT_SOURCE_DIR})
target_link_libraries(ex4.out matrix ${CMAKE_THREAD_LIBS_INIT})
>>>>>>> 537709e809e8dd667d4d72380a3ef49c44a97eee
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)