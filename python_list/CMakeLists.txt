add_executable(python_list main.cpp)

target_link_libraries(python_list
    PRIVATE
    myutils
    term
    tui
)