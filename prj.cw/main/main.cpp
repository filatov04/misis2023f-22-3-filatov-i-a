#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <stdio.h>
#include <igl/readOBJ.h>
#include <igl/writeOBJ.h>
#include <igl/opengl/glfw/Viewer.h>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include "ImFileBrowser.h"
#include "morph.hpp"


static void error(int error, const char* description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void TextCentered(const char* text) {
    auto windowWidth = ImGui::GetWindowSize().x;
    auto windowHeight = ImGui::GetWindowSize().y;
    auto textWidth  = ImGui::CalcTextSize(text).x;
    auto textHeight  = ImGui::CalcTextSize(text).y;

    ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
    ImGui::SetCursorPosY((windowHeight - textHeight) - 100);
    ImGui::Text(text);
}

Eigen::MatrixXd v0, v_horns, v_lips, v_chin, v_cheekbones, v_nose, D_morph, Union, v_cheek;
Eigen::MatrixXi f0, f_horns, f_lips, f_chin, f_cheekbones, f_nose, f_cheek;

void slaider_nose(/*igl::opengl::glfw::Viewer& viewer_temp,*/ int& key, int& last_key) {
    D_morph = (v_nose - v0) / 5;
    Union = Union + (key - last_key) * D_morph;
}

void slaider_cheek(/*igl::opengl::glfw::Viewer& viewer_temp,*/ int& key, int& last_key) {
    D_morph = (v_cheek - v0) / 5;
    Union = Union + (key - last_key) * D_morph;
}

void slaider_cheekbones(/*igl::opengl::glfw::Viewer& viewer_temp,*/ int& key, int& last_key) {
    D_morph = (v_cheekbones - v0) / 5;
    Union = Union + (key - last_key) * D_morph;
}

void slaider_chin(/*igl::opengl::glfw::Viewer& viewer_temp,*/ int& key, int& last_key) {
    D_morph = (v_chin - v0) / 5;
    Union = Union + (key - last_key) * D_morph;
}

void slaider_horns(/*igl::opengl::glfw::Viewer& viewer_temp,*/ int& key, int& last_key) {
    D_morph = (v_horns - v0) / 5;
    Union = Union + (key - last_key) * D_morph;
}

void slaider_lips(/*igl::opengl::glfw::Viewer& viewer_temp,*/ int& key, int& last_key) {
    D_morph = (v_lips - v0) / 5;
    Union = Union + (key - last_key) * D_morph;
}

void pre_draw(igl::opengl::glfw::Viewer& viewer_temp) {
    viewer_temp.data().set_vertices(Union);
    viewer_temp.data().compute_normals();
}
bool isMatrixEmpty(const Eigen::MatrixXd& mat) {
    return mat.rows() == 0 || mat.cols() == 0;
}

int main(int, char**)
{
    igl::readOBJ("..\\..\\..\\prj.cw\\main\\objects\\cheekbones1.obj", v_cheekbones, f_cheekbones);
    igl::readOBJ("..\\..\\..\\prj.cw\\main\\objects\\chin1.obj", v_chin, f_chin);
    igl::readOBJ("..\\..\\..\\prj.cw\\main\\objects\\horns1.obj", v_horns, f_horns);
    igl::readOBJ("..\\..\\..\\prj.cw\\main\\objects\\lips1.obj", v_lips, f_lips);
    igl::readOBJ("..\\..\\..\\prj.cw\\main\\objects\\nose1.obj", v_nose, f_nose);
    igl::readOBJ("..\\..\\..\\prj.cw\\main\\objects\\cheek1.obj", v_cheek, f_cheek);
    igl::opengl::glfw::Viewer viewer;

    //viewer.data().set_mesh(V, F);
    viewer.launch_init();
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    int width = mode->width;
    int height = mode->height;
    glfwSetWindowSize(viewer.window, width / 2, height);
    glfwSetWindowPos(viewer.window, width * 0.5f, 0);


    GLFWwindow* window = glfwCreateWindow(mode->width*0.5f, mode->height, "Simur", nullptr, nullptr);
    glfwSetWindowPos(window, 0, 0);
    if (window == nullptr)
        return 1;

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (io, window, true);

    // Инициализация ImGui для работы с OpenGL и GLFW
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    //ImGui_ImplGlfw_InitForOpenGL(viewer.window(), true);
    ImGui_ImplOpenGL3_Init("#version 410");

    // Our state
    //bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    std::vector<std::pair<int, std::string>> data;

    ImGui::FileBrowser FileDialog(ImGuiFileBrowserFlags_ConfirmOnEnter);
    ImGui::FileBrowser FileDialog2(ImGuiFileBrowserFlags_ConfirmOnEnter | ImGuiFileBrowserFlags_SelectDirectory);
    //fileDialog.SetTypeFilters({ ".gitignore" });
    FileDialog.SetTitle("Open mesh");
    FileDialog2.SetTitle("Save mesh");
    //FileDialog.SetTypeFilters({ ".off", ".obj" });

    //std::string workPath = "";
    //std::string readPath = "";
    int value = 0;
    int value1 = 0;
    int value2 = 0;
    int value3 = 0;
    int value4 = 0;
    int value5 = 0;



    while (!glfwWindowShouldClose(window) && !glfwWindowShouldClose(viewer.window))
    {
        glfwMakeContextCurrent(viewer.window);
        processInput(viewer.window);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        viewer.draw();
        glfwSwapBuffers(viewer.window);
        glfwPollEvents();



        glfwMakeContextCurrent(window);
        processInput(window);
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        //int x, y;
        glfwGetWindowSize(window, &width, &height);

        ImVec2 window_size = ImVec2(static_cast<float>(width), static_cast<float>(height));
        ImGui::SetNextWindowSize(window_size, ImGuiCond_Always);
        ImGui::SetNextWindowPos(ImVec2(0, 0));

        // Сохранить текущий цвет окна
        ImGuiStyle* style = &ImGui::GetStyle();
        ImVec4 old_window_color = style->Colors[ImGuiCol_WindowBg];

// Изменить цвет окна на красный
        style->Colors[ImGuiCol_WindowBg] = ImVec4(0.302f, 0.0f, 0.514f, 0.1f);
        ImGui::Begin("Properties", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize);
        ImGui::SetWindowFontScale(3);
        if (ImGui::CollapsingHeader("Mesh", ImGuiTreeNodeFlags_DefaultOpen))
        {

            if (ImGui::Button("Open..."))
            {
                FileDialog.SetTypeFilters({".obj"}); // Поддерживаемые форматы моделей
                FileDialog.Open();
            }
            ImGui::SameLine(0, 5.0f);
            ImGui::Text("< ... >");
        }
        FileDialog.SetWindowSize(800,600);
        FileDialog.Display();
        if (ImGui::CollapsingHeader("Slider") && !isMatrixEmpty(v0))
        {
            ImGuiStyle* style = &ImGui::GetStyle();
            style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.9f, 0.5f, 0.9f, 1.0f);
            int temp_value;
            temp_value = value;
            ImGui::SliderInt("nose", &value, -5, 5);
            if (value != temp_value) {
                slaider_nose(/*viewer,*/ value, temp_value);
                pre_draw(viewer);
            }
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            style->Colors[ImGuiCol_SliderGrab] = ImVec4(1.0f, 0.5f, 0.5f, 1.0f);
            int temp_value1;
            temp_value1 = value1;
            ImGui::SliderInt("cheekbones", &value1, -5, 5);
            if (value1 != temp_value1) {
                slaider_cheekbones(/*viewer,*/ value1, temp_value1);
                pre_draw(viewer);
            }
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            style->Colors[ImGuiCol_SliderGrab] = ImVec4(1.0f, 1.0f, 0.0f, 1.0f);
            int temp_value3;
            temp_value3 = value3;
            ImGui::SliderInt("horns", &value3, -5, 5);
            if (value3 != temp_value3) {
                slaider_horns(/*viewer,*/ value3, temp_value3);
                pre_draw(viewer);
            }
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.0f, 1.0f, 0.0f, 1.0f);
            int temp_value4;
            temp_value4 = value4;
            ImGui::SliderInt("lips", &value4, -5, 5);
            if (value4 != temp_value4) {
                slaider_lips(/*viewer,*/ value4, temp_value4);
                pre_draw(viewer);
            }
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.5f, 0.0f, 0.5f, 1.0f);
            int temp_value5;
            temp_value5 = value5;
            ImGui::SliderInt("cheek", &value5, -5, 5);
            if (value5 != temp_value5) {
                slaider_cheek(/*viewer,*/ value5, temp_value5);
                pre_draw(viewer);
            }
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            ImGui::Spacing();
            style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.0f, 0.0f, 1.0f, 1.0f);
            int temp_value2;
            temp_value2 = value2;
            ImGui::SliderInt("chin", &value2, -5, 5);
            if (value2 != temp_value2) {
                slaider_chin(/*viewer,*/ value2, temp_value2);
                pre_draw(viewer);
            }
        }

        if (ImGui::CollapsingHeader("Save") && !isMatrixEmpty(v0)) {
            if (ImGui::Button("Save to directory \"Save\" ")) {
                auto currentTime = std::chrono::system_clock::now();

                // Преобразование времени в строку
                std::time_t currentTimeT = std::chrono::system_clock::to_time_t(currentTime);
                std::tm *currentTM = std::localtime(&currentTimeT);

                // Форматирование времени в строку
                std::stringstream ss;
                ss << std::put_time(currentTM, "%Y%m%d_%H%M%S");
                std::string currentTimeString = ss.str();
                std::string face = "face_save_";
                std::string obj = ".obj";
                std::string save = "save/";
                std::string save2 = "../../../prj.cw/main/";
                currentTimeString = save2 + save + face + currentTimeString + obj;
                igl::writeOBJ(currentTimeString, Union, f0);
                ImGui::OpenPopup("Save");
            }
            if (ImGui::BeginPopupModal("Save"))
            {
                ImGui::Text("The file was saved successfully");
                if (ImGui::Button("OK"))
                    ImGui::CloseCurrentPopup();
                ImGui::EndPopup();
            }
            if (ImGui::Button("save to any location"))
            {
                FileDialog2.Open();
                FileDialog2.SetTypeFilters({".obj"});

            }
        }
        FileDialog2.SetWindowSize(800,600);
        FileDialog2.Display();

        TextCentered("To exit the application, press ESCAPE");
        ImGui::End();
        if (FileDialog.HasSelected()) {
            Eigen::MatrixXd V;
            Eigen::MatrixXi F;
            std::string file_path = FileDialog.GetSelected().string();
            FileDialog.Close();

            viewer.data().clear();
            igl::readOBJ(file_path, V, F);
            v0 = V;
            f0 = F;
            Union = V;

            viewer.data().set_mesh(V, F);
            FileDialog.ClearSelected();

        }
        if (FileDialog2.HasSelected()) {
            std::string file_path2 = FileDialog2.GetSelected().string();
            auto currentTime = std::chrono::system_clock::now();

            // Преобразование времени в строку
            std::time_t currentTimeT = std::chrono::system_clock::to_time_t(currentTime);
            std::tm *currentTM = std::localtime(&currentTimeT);

            // Форматирование времени в строку
            std::stringstream ss;
            ss << std::put_time(currentTM, "%Y%m%d_%H%M%S");
            std::string currentTimeString = ss.str();
            std::string face2 = "save_face";
            std::string obj = ".obj";
            std::string a = "/";
            currentTimeString = file_path2 + a + face2 + currentTimeString + obj;
            igl::writeOBJ(currentTimeString, Union, f0);


            FileDialog2.Close();
            FileDialog2.ClearSelected();

        }


        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}