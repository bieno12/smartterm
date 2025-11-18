cmake_minimum_required(VERSION 3.10.0)

add_executable(task1)

target_sources(task1
    PRIVATE
    main.cpp
)
target_link_libraries(task1
    PRIVATE
    term
)