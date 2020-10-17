set(HEADER_LIST 
    "${PROJECT_SOURCE_DIR}/include/graphic.h" 
    "${PROJECT_SOURCE_DIR}/include/circle.h"
    "${PROJECT_SOURCE_DIR}/include/polygon.h")

add_library(binary_library circle.cpp polygon.cpp ${HEADER_LIST}) # maybe static

target_include_directories(binary_library PUBLIC 
../include 
${OPENGL_INCLUDE_DIR}
${PROJECT_SOURCE_DIR}/third_party/nanovg/src/) 

# target_link_libraries(binary_library PUBLIC nanovg ${OPENGL_LIBRARIES} SDL2::SDL2)

target_compile_features(binary_library PUBLIC cxx_std_11)