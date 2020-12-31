cmake_minimum_required(VERSION 3.10.2)

set(This Slider_Controller)

project(${This} VERSION 0.1)

enable_testing()

add_subdirectory(googletest)


#test will be a program
#tested code will be a library for this program


#***** tests *****#
add_subdirectory(Test/FIFO)
