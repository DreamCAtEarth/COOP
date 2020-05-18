cmake_minimum_required(VERSION 3.13)
project(COOP C)

set(CMAKE_C_STANDARD 11)
set(TARGET_NAME "COOP")

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

add_executable(${TARGET_NAME}

        sources/main.c                  # Public Static context
        sources/objectModel.h           # Object Oriented Lib
        sources/objectModel.c

        sources/coop/coop.h             # Package vlDzoKUd
        sources/coop/coop.c
        sources/coop/Object.h
        sources/coop/Object.c           # class kGAzHwmx
        sources/coop/Derived.h
        sources/coop/Derived.c          # class ddUKsuMN
        sources/coop/Another.h
        sources/coop/Another.c          # class lbdtYEkR
        sources/coop/Geometric.h
        sources/coop/Geometric.c        # class YPnOLrQT
        sources/coop/Square.h
        sources/coop/Square.c           # class UQZwMHfN

        sources/coop/lang/lang.h        # Package nnVYoBNR
        sources/coop/lang/lang.c
        sources/coop/lang/Bool.h
        sources/coop/lang/Bool.c        # class BwXbIZdw
        sources/coop/lang/ToTest.h      # interface

        sources/util/util.h             # Package kdzvSGAN
        sources/util/util.c
        sources/util/Object.h
        sources/util/Object.c           # class KPLGWrfu
)

if(MSVC)
    target_compile_options(${TARGET_NAME} PRIVATE /W4 /WX)
else()
    target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -Wconversion)
endif()
# -Wstrict-prototypes -Wmissing-prototypes -pedantic -Werror

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "Main")