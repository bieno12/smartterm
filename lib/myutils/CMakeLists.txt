add_library(myutils)

target_sources(myutils
    PRIVATE
    cstring.cpp

    PUBLIC
    FILE_SET HEADERS
    BASE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    FILES
        include/myutils/cstring.h
)

target_include_directories(myutils
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)