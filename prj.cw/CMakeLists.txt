# Добавьте опцию компилятора /bigobj
add_compile_options(/bigobj)


# Добавьте исполняемый файл
add_executable(
    Simur
    main/main.cpp
    imgui/imgui.h
    imgui/imgui.cpp
    imgui/imconfig.h
    imgui/imgui_demo.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_internal.h
    imgui/imgui_tables.cpp
    imgui/imgui_widgets.cpp
    imgui/imstb_rectpack.h
    imgui/imstb_textedit.h
    imgui/imstb_truetype.h

    imgui/backends/imgui_impl_glfw.h
    imgui/backends/imgui_impl_glfw.cpp

    imgui/backends/imgui_impl_opengl3.h
    imgui/backends/imgui_impl_opengl3.cpp
    imgui/backends/imgui_impl_opengl3_loader.h
    	main/morph.hpp
    	main/morph.cpp
	#ImFileBrowser.h
)

find_package(OpenGL REQUIRED)

find_package(glfw3 CONFIG REQUIRED)

find_package(glm REQUIRED)

find_package(glew REQUIRED)

find_package(libigl REQUIRED)

target_include_directories(Simur PUBLIC
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/imgui>
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends>
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/main/>
)


target_link_libraries(
        Simur
        GLEW::GLEW
        OpenGL::GL
        glfw
        glm::glm
        igl::igl_core igl::igl_opengl igl::igl_glfw
)