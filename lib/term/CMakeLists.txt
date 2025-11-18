add_library(term)

target_sources(term
    PRIVATE
        term.cpp
        input.cpp

    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            ${CMAKE_CURRENT_SOURCE_DIR}/include
        FILES
            include/term/term.h
            include/term/input.h
)

target_include_directories(term
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)