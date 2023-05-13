set(SOURCES
        objectModel.c
        objectModel.h
        exceptionHandler.c
        exceptionHandler.h

        containers/containers.h
        containers/linkedList.c
        containers/linkedList.h

        coop/coop.c
        coop/coop.h
        coop/Object.c
        coop/Object.h
        coop/Derived.c
        coop/Derived.h
        coop/Another.c
        coop/Another.h
        coop/Geometric.c
        coop/Geometric.h
        coop/Square.c
        coop/Square.h

        coop/lang/lang.c
        coop/lang/lang.h
        coop/lang/Bool.c
        coop/lang/Bool.h

        util/util.c
        util/util.h
        util/Object.c
        util/Object.h)

add_library(${SRC} ${SOURCES})

if(CMAKE_COMPILER_IS_GNUCC)
    target_compile_options(${SRC} PRIVATE ${GNUC_OPTIONS})
endif(CMAKE_COMPILER_IS_GNUCC)

if(MSVC)
    target_compile_options(${SRC} PRIVATE ${MSVC_OPTIONS})
endif(MSVC)

set_target_properties(${SRC} PROPERTIES C_STANDARD ${CMAKE_C_STANDARD} OUTPUT_NAME ${SRC})

define_file_basename_for_sources(${SRC})
