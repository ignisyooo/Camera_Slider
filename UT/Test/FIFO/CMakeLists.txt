cmake_minimum_required(VERSION 3.10.2)

set(This FIFO_UT)

#***** variables *****#
set(APP_DIR ../../..)
set(SOURCE_DIR ${APP_DIR}/Core/Src)


#***** library *****#
include_directories(./stubs)
include_directories(${APP_DIR}/Core/Inc)

add_library(FIFO_UT_lib 
    ${SOURCE_DIR}/FIFO.c
)


#***** test *****#
add_executable(${This} 
    FIFO_UT.cpp
)

target_link_libraries(${This} PUBLIC
    gtest_main
    FIFO_UT_lib
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
