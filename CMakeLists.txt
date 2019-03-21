cmake_minimum_required(VERSION 3.13)
project(COOP C)

set(CMAKE_C_STANDARD 99)

add_executable(COOP sources/main.c
        sources/Object.c
        sources/Object.h

        sources/objectModel.c
        sources/objectModel.h

        sources/overriding.h

        sources/objectException.c
        sources/objectException.h)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "Main")