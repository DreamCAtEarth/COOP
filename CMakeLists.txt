cmake_minimum_required(VERSION 3.13)
project(COOP C)

set(CMAKE_C_STANDARD 11)
set(TARGET_NAME "COOP")

add_executable(${TARGET_NAME}

        sources/main.c
        sources/objectModel.h
        sources/objectModel.c
        sources/exceptionManager.h
        sources/exceptionManager.c

        sources/coop/coop.h
        sources/coop/coop.c
        sources/coop/Object.h
        sources/coop/Object.c
        sources/coop/Derived.h
        sources/coop/Derived.c
        sources/coop/Another.h
        sources/coop/Another.c
        sources/coop/Geometric.h
        sources/coop/Geometric.c
        sources/coop/Square.h
        sources/coop/Square.c

        sources/coop/lang/lang.h
        sources/coop/lang/Bool.h
        sources/coop/lang/Bool.c
        sources/coop/lang/ToTest.h

        sources/util/util.h
        sources/util/Object.h
        sources/util/Object.c
        )

if(MSVC)
    target_compile_options(${TARGET_NAME} PRIVATE /W4 /WX)
else()
    target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -Wconversion)
endif()
# -pedantic -Werror

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "Main")