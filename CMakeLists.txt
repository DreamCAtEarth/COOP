cmake_minimum_required(VERSION 3.15)
project(COOP C)

set(CMAKE_C_STANDARD 11)
set(MAIN_TARGET "COOP")

# Availables ids for classes and packages for a COOP :
# pkZncgNI
# UbgZseDt
# eVMHzbxS
# eGNDuOBB
# EdKwPHqQ
# YJpSZFiL
# vqoWPZRY
# vjjdVitG
# JjDrSiUB

add_executable(${MAIN_TARGET}
        sources/main.c                              # Public Static context
        sources/objectModel.c                       # Object Oriented Lib
        sources/objectModel.h
        sources/exceptionManager.c                  # Exception Manager
        sources/exceptionManager.h

        sources/collections/simplyLinkedList.c      # Collections Available
        sources/collections/simplyLinkedList.h

        sources/coop/coop.c                         # Package vlDzoKUd
        sources/coop/coop.h
        sources/coop/Object.c                       # class kGAzHwmx
        sources/coop/Object.h
        sources/coop/Derived.c                      # class ddUKsuMN
        sources/coop/Derived.h
        sources/coop/Another.c                      # class lbdtYEkR
        sources/coop/Another.h
        sources/coop/Geometric.c                    # class YPnOLrQT
        sources/coop/Geometric.h
        sources/coop/Square.c                       # class UQZwMHfN
        sources/coop/Square.h

        sources/coop/lang/lang.c                    # Package nnVYoBNR
        sources/coop/lang/lang.h
        sources/coop/lang/Bool.c                    # class BwXbIZdw
        sources/coop/lang/Bool.h
        sources/coop/lang/ToTest.h                  # interface

        sources/util/util.c                         # Package kdzvSGAN
        sources/util/util.h
        sources/util/Object.c                       # class KPLGWrfu
        sources/util/Object.h
        )

if(MSVC)
    target_compile_options(${MAIN_TARGET} PRIVATE /W4 /WX)
else()
    target_compile_options(${MAIN_TARGET} PRIVATE -Wall -Wextra -Wconversion -Wmissing-prototypes)
endif()
# -pedantic -Werror

set_target_properties(${MAIN_TARGET} PROPERTIES OUTPUT_NAME "Main")