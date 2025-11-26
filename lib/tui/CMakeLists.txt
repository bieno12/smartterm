add_library(tui)

target_sources(tui
    PRIVATE
        tui.cpp
        menu.cpp
        page.cpp
        
        input_field.cpp
        button.cpp
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            ${CMAKE_CURRENT_SOURCE_DIR}/include
        FILES
            include/term/tui.h

    PRIVATE
        menu.h
        page.h

        input_field.h
        button.h
)

target_link_libraries(tui term)
target_include_directories(tui
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
