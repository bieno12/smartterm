add_executable(complex complex.cpp main.cpp)

target_link_libraries(complex
    PRIVATE
    myutils
    term
    tui
)