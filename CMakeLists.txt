cmake_minimum_required(VERSION 3.13)
project(COOP C)

set(CMAKE_C_STANDARD 90)

add_executable(
        COOP

        sources/main.c
        sources/objectModel.c
        sources/objectModel.h

        sources/coop/coop.c
        sources/coop/coop.h
        sources/coop/Object.c
        sources/coop/Object.h

        sources/util/util.c
        sources/util/util.h
        sources/util/Object.c
        sources/util/Object.h)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "Main")