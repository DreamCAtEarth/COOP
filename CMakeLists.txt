cmake_minimum_required(VERSION 3.13)
project(COOP C)

set(CMAKE_C_STANDARD 90)

add_executable(COOP sources/main.c sources/Object.c sources/Object.h sources/DerivedObject.c sources/DerivedObject.h sources/ObjectException.c sources/ObjectException.h)