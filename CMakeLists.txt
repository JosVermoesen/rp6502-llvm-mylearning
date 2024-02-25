cmake_minimum_required(VERSION 3.18)
add_subdirectory(tools)
set(LLVM_MOS_PLATFORM rp6502)
find_package(llvm-mos-sdk REQUIRED)
project(MY-RP6502-PROJECT)

add_executable(ascii)
rp6502_executable(ascii)
target_sources(ascii PRIVATE
    src/ascii.c
)

add_executable(searchandsort)
rp6502_executable(searchandsort)
target_sources(searchandsort PRIVATE
    src/searchandsort.c
)

add_executable(xmastree)
rp6502_executable(xmastree)
target_sources(xmastree PRIVATE
    src/xmastree.c
)

add_executable(hello)
rp6502_executable(hello)
target_sources(hello PRIVATE
    src/main.c
)
