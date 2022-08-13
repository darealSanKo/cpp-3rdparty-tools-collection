cmake_minimum_required(VERSION 3.16)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. You may need to remove CMakeCache.txt. ")
endif()

project(cpp-3rdparty-tools-collection)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Git)

if(NOT Git_FOUND)
  message(WARNING "Git not found.")
endif()

if(Git_FOUND)
  execute_process(COMMAND git -C ${PROJECT_SOURCE_DIR} submodule update --init --recursive)
endif()

if(WIN32)
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif()

add_subdirectory(3rdparty/spdlog)
if(WIN32)
  set_target_properties(spdlog PROPERTIES FOLDER "3rdparty")
endif()

add_subdirectory(src)
