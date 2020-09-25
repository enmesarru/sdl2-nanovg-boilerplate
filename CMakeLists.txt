cmake_minimum_required(VERSION 3.0.0)
project(binary_reverse VERSION 0.1.0)

include(CTest)
enable_testing()


add_executable(binary_reverse main.cpp)
target_compile_features(binary_reverse PRIVATE cxx_std_17)

#SDL2
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

if(NOT OPENGL_FOUND) 
    message("ERROR: OpenGL not found")
endif(NOT OPENGL FOUND)

target_include_directories(binary_reverse PUBLIC ${SDL2_INCLUDE_DIRS})
target_include_directories(binary_reverse PUBLIC ${OPENGL_INCLUDE_DIR})

target_link_libraries(binary_reverse PRIVATE 
    binary_library 
    #${SDL2_LIBRARIES} 
    imgui
    nanovg 
    ${OPENGL_LIBRARIES})

target_link_libraries(binary_reverse PUBLIC SDL2::SDL2)

add_subdirectory(third_party)
add_subdirectory(src)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
