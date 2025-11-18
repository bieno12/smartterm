cmake_minimum_required(VERSION 3.10.0)

add_executable(task4)

target_sources(task4
    PRIVATE
    main.cpp
)
target_link_libraries(task4
    PRIVATE
    myutils
)