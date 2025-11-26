cmake_minimum_required(VERSION 3.10.0)
project(smartterm  LANGUAGES C CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
file(GLOB_RECURSE SRC_FILES
    CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

# Create one executable from all sources
add_executable(${PROJECT_NAME} ${SRC_FILES})


add_subdirectory(lib/term)
add_subdirectory(lib/tui)
add_subdirectory(lib/myutils)


target_link_libraries(${PROJECT_NAME} 
    PRIVATE
    term
    tui
    myutils
)