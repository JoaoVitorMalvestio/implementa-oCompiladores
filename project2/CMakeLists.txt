# Declaration et nommage du projet
project(parser)

# Minimum version of CMake to build this project
cmake_minimum_required(VERSION 2.6)

# Includes
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(/usr/lib/llvm-10/include)
#include_directories(${LLVM_INCLUDE_DIRS})

# Packages
find_package(BISON)
find_package(FLEX)
find_package(LLVM REQUIRED CONFIG)

message(STATUS "Include LLVM ${LLVM_INCLUDE_DIRS}")
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

# Variables
set(CXX "clang++")
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -W -Werror -pedantic -g")
set(CMAKE_CXX_FLAGS "-O3 -Wall -W -pedantic")

# Files
file(GLOB HH_FILES *.hh)
file(GLOB SRC_FILES *.cc)

# BISON and FLEX
bison_target(Parser parser.yy ${CMAKE_CURRENT_BINARY_DIR}/parser.cc)
flex_target(Scanner scanner.ll ${CMAKE_CURRENT_BINARY_DIR}/scanner.cc)
add_flex_bison_dependency(Scanner Parser)

# llvm
add_definitions(${LLVM_DEFINITIONS})

# Output directoru
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# Add the binary and sources
add_executable(
  tc
  ${HH_FILES}
  ${SRC_FILES}
  ${FLEX_Scanner_OUTPUTS}
  ${BISON_Parser_OUTPUTS}
)

llvm_map_components_to_libnames(llvm_libs support core irreader)
target_link_libraries(tc ${llvm_libs})
