cmake_minimum_required(VERSION 3.13)
project(COOP C)

set(CMAKE_C_STANDARD 99)

add_executable(COOP

        sources/main.c
        sources/objectModel.c
        sources/objectModel.h
        sources/exceptionManager.c
        sources/exceptionManager.h

        sources/coop/coop.h
        sources/coop/Object.c
        sources/coop/Object.h
        sources/coop/Derived.c
        sources/coop/Derived.h
        sources/coop/Another.c
        sources/coop/Another.h
        sources/coop/Geometric.c
        sources/coop/Geometric.h

        sources/util/util.h
        sources/util/Object.c
        sources/util/Object.h)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "Main")