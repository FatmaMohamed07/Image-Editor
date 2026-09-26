cmake_minimum_required(VERSION 3.10)


project(MyImageProject CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(MyImageProject
        main.cpp
        Image_Class.h
        stb_image.h
        stb_image_write.h
)