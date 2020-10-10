set(HEADER_LIST 
    "${PROJECT_SOURCE_DIR}/include/graphic.h" 
    "${PROJECT_SOURCE_DIR}/include/circle.h")

add_library(binary_library circle.cpp ${HEADER_LIST}) # maybe static

target_include_directories(binary_library PUBLIC ../include)

target_compile_features(binary_library PUBLIC cxx_std_11)