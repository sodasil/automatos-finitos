cmake_minimum_required(VERSION 3.15)

project(Reconhecedor LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)

find_package(FLTK REQUIRED)

add_executable(Reconhecedor
    main.cpp
)

target_link_libraries(Reconhecedor
    PRIVATE
    fltk
)

if(WIN32)
    target_link_libraries(Reconhecedor
        PRIVATE
        ws2_32
        comctl32
        ole32
        uuid
    )
endif()

if(MINGW)
    target_link_options(Reconhecedor PRIVATE
        -static-libgcc
        -static-libstdc++
    )
endif()