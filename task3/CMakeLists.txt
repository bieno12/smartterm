cmake_minimum_required(VERSION 3.10.0)

add_executable(task3)

target_sources(task3
    PRIVATE
    main.cpp
)
target_link_libraries(task3
    PRIVATE
    term
    tui
)