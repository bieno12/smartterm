add_executable(test_string main.cpp)

target_link_libraries(test_string
    PRIVATE
    myutils
    term
    tui
)