cmake_minimum_required(VERSION 3.15)
project(COOP C ASM)
set(CMAKE_C_STANDARD 11)

set(GCC_SILENT_WARNINGS -Wno-maybe-uninitialized -Wno-expansion-to-defined)
set(GCC_BONUS_WARNINGS -Wformat=2 -Wformat-overflow=2 -Wformat-truncation=2 -Wformat-security -Wnull-dereference -Wvla -Wtrampolines -Warray-bounds=2 -Wimplicit-fallthrough=3 -Wshift-overflow=2 -Wcast-qual -Wstringop-overflow=4 -Wconversion -Warith-conversion -Wlogical-op -Wduplicated-cond -Wduplicated-branches -Wformat-signedness -Wmissing-prototypes -Wshadow -Wstrict-overflow=4 -Wundef -Wcast-align=strict)
# -Werror -Wstack-protector -Walloca -Wtraditional-conversion -Wstrict-prototypes -Wswitch-default -Wswitch-enum -Wstack-usage=1000000 -Wpadded
set(GCC_DEBUG_FLAGS -O3 -fPIE -g)
# -fPIE -fno-omit-frame-pointer -fno-optimize-sibling-calls -fwrapv -fstack-protector-strong -fstack-clash-protection -fpack-struct=8 -fms-extensions -fcf-protection=full|return|branch -Os -O1 -O2 -O3 -pie -D_FORTIFY_SOURCE=3 -g3 -debug
set(GCC_LINKER_FLAGS -Wl,-z,relro -Wl,-z,now -Wl,-z,noexecstack -Wl,-z,separate-code)
set(GNUC_OPTIONS -Wall -Wextra -Wpedantic ${GCC_DEBUG_FLAGS} ${GCC_BONUS_WARNINGS} ${GCC_SILENT_WARNINGS} ${GCC_LINKER_FLAGS})
set(MSVC_OPTIONS /Wall /WX /sdl /guard:cf /guard:ehcont /CETCOMPAT /fsanitize=address /analyze)

# don't use Google sanitizers and Valgrind / Dr Memory together, use Valgrind / Dr Memory for leaks only
# options : -fsanitize=thread -fPIE -pie (cf https://mropert.github.io/2018/02/02/pic_pie_sanitizers/)
# To efficiently use MSan (clang only), compile your program with :
# -fsanitize=memory -fPIE -pie -fno-omit-frame-pointer -g, add -fno-optimize-sibling-calls and -O1 or later.
# -fsanitize=address -fsanitize=pointer-compare -fsanitize=pointer-subtract -fsanitize=leak -fno-omit-frame-pointer -fsanitize=undefined -fsanitize=bounds-strict -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fsanitize-undefined-trap-on-error
# export ASAN_OPTIONS=strict_string_checks=1:detect_stack_use_after_return=1:check_initialization_order=1:strict_init_order=1:detect_invalid_pointer_pairs=2
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -fsanitize=undefined -fPIE -pie -fno-omit-frame-pointer -g")

set(ASM_OPTIONS "-x assembler-with-cpp")
set(CMAKE_ASM_FLAGS "${C_FLAGS} ${ASM_OPTIONS}")

# Helper function to add preprocesor definition of FILE_BASENAME
# to pass the filename without directory path for debugging use.
#
# Example:
#
#   define_file_basename_for_sources(my_target)
#
# Will add -DFILE_BASENAME="filename" for each source file depended on
# by my_target, where filename is the name of the file.
#
function(define_file_basename_for_sources targetname)
    get_target_property(source_files "${targetname}" SOURCES)
    foreach(sourcefile ${source_files})
        # Add the FILE_BASENAME=filename compile definition to the list.
        get_filename_component(basename "${sourcefile}" NAME_WE)
        # Add the DIR_NAME=dir compile definition to the list
        get_filename_component(dirname "${sourcefile}" PATH)
        get_filename_component(lastDirname "${dirname}" NAME)
        # Set the updated compile definitions on the source file.
        string(TOUPPER "${lastDirname}" lastDirType)
        set_property(
                SOURCE "${sourcefile}" APPEND
                PROPERTY COMPILE_DEFINITIONS
                "ME=${basename}" "MY_NAME=\"${basename}\""
                "MYSELF=\"${basename}.h\"" "MYSPACE=\"${lastDirname}.h\"")
    endforeach()
endfunction()

include_directories(src)
#link_directories(libs/my_lib)

set(SRC "coopMain")
set(TEST "coopTest")

add_subdirectory(src)
enable_testing()
add_subdirectory(test)
