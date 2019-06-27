cmake_minimum_required(VERSION 3.14)
project(RegularExpression)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD_REQUIRED True)

aux_source_directory(. SRCS)

add_executable(RegularExpression ${SRCS})