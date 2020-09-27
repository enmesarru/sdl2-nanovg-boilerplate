#NANOVG CONFIGURATION
set(NANOVG_SOURCES 
    ${PROJECT_SOURCE_DIR}/third_party/nanovg/src/fontstash.h
    ${PROJECT_SOURCE_DIR}/third_party/nanovg/src/nanovg.h
    ${PROJECT_SOURCE_DIR}/third_party/nanovg/src/nanovg_gl_utils.h
    ${PROJECT_SOURCE_DIR}/third_party/nanovg/src/nanovg_gl.h
    ${PROJECT_SOURCE_DIR}/third_party/nanovg/src/nanovg.c
    ${PROJECT_SOURCE_DIR}/third_party/nanovg/src/stb_image.h
    ${PROJECT_SOURCE_DIR}/third_party/nanovg/src/stb_truetype.h)

add_library(nanovg ${NANOVG_SOURCES})
# target_link_libraries(nanovg PUBLIC GLEW)
target_include_directories(nanovg PUBLIC ${PROJECT_SOURCE_DIR}/third_party/nanovg/src/)

# IMGUI_CONFIGURATION
set(IMGUI_SOURCES
    ${PROJECT_SOURCE_DIR}/third_party/imgui/imconfig.h
    ${PROJECT_SOURCE_DIR}/third_party/imgui/imgui.h
    ${PROJECT_SOURCE_DIR}/third_party/imgui/imgui.cpp
    ${PROJECT_SOURCE_DIR}/third_party/imgui/imgui_internal.h
    ${PROJECT_SOURCE_DIR}/third_party/imgui/imgui_demo.cpp
    ${PROJECT_SOURCE_DIR}/third_party/imgui/imgui_draw.cpp
    ${PROJECT_SOURCE_DIR}/third_party/imgui/imgui_widgets.cpp
    ${PROJECT_SOURCE_DIR}/third_party/imgui/imstb_rectpack.h
    ${PROJECT_SOURCE_DIR}/third_party/imgui/imstb_textedit.h
    ${PROJECT_SOURCE_DIR}/third_party/imgui/imstb_truetype.h

    ${PROJECT_SOURCE_DIR}/third_party/imgui/examples/imgui_impl_sdl.h
    ${PROJECT_SOURCE_DIR}/third_party/imgui/examples/imgui_impl_sdl.cpp
    ${PROJECT_SOURCE_DIR}/third_party/imgui/examples/imgui_impl_opengl3.h
    ${PROJECT_SOURCE_DIR}/third_party/imgui/examples/imgui_impl_opengl3.cpp
)

add_library(imgui ${IMGUI_SOURCES})
#make sdl2 avaliable to imgui
target_include_directories(imgui PUBLIC ${SDL2_INCLUDE_DIRS})

target_link_libraries(imgui PUBLIC SDL2::SDL2)

target_include_directories(imgui PUBLIC 
    ${PROJECT_SOURCE_DIR}/third_party/imgui 
    ${PROJECT_SOURCE_DIR}/third_party/imgui/examples)

target_compile_definitions(imgui PUBLIC 
    IMGUI_IMPL_OPENGL_LOADER_CUSTOM=<SDL_opengl.h>  GL_GLEXT_PROTOTYPES=1)