set(SOURCES
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

add_library(imgui ${SOURCES})
#make sdl2 avaliable to imgui
target_include_directories(imgui PUBLIC ${SDL2_INCLUDE_DIRS})

target_link_libraries(imgui PUBLIC SDL2::SDL2)

target_include_directories(imgui PUBLIC 
    ${PROJECT_SOURCE_DIR}/third_party/imgui 
    ${PROJECT_SOURCE_DIR}/third_party/imgui/examples)

target_compile_definitions(imgui PUBLIC 
    IMGUI_IMPL_OPENGL_LOADER_CUSTOM=<SDL_opengl.h>  GL_GLEXT_PROTOTYPES=1)