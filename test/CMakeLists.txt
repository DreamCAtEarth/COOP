add_executable(
        ${TEST}
        mainTest.c) # main usage : 1)operate : ǀ Ͼ Ͽ Ξ Ø 2)new : ǁ Ͻ 3)main with args : Ǝ() Ǝ ENV_

target_link_libraries(${TEST} ${SRC} m backtrace)

if(CMAKE_COMPILER_IS_GNUCC)
    target_compile_options(${TEST} PRIVATE ${GNUC_OPTIONS})
endif(CMAKE_COMPILER_IS_GNUCC)
if(MSVC)
    target_compile_options(${TEST} PRIVATE ${MSVC_OPTIONS})
endif(MSVC)

set_target_properties(${TEST} PROPERTIES C_STANDARD ${CMAKE_C_STANDARD} OUTPUT_NAME ${TEST})

add_test(${TEST} ${TEST})

define_file_basename_for_sources(${TEST})
