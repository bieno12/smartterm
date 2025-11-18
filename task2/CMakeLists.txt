cmake_minimum_required(VERSION 3.10.0)

add_executable(task2)

target_sources(task2
    PRIVATE
    main.cpp
)
target_link_libraries(task2
    PRIVATE
    term
    tui
)