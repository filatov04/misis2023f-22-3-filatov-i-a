//
// Created by Katya on 11.01.2024.
//
#include "morph.hpp"
// ------------------------

Morph::Morph() {
    std::cout << "Check corrects paths in method init_bones" << std::endl;
}



bool Morph::nose(igl::opengl::glfw::Viewer& viewer_temp, unsigned int key) {
    switch (key) {
        case '1':
            Union = Union + (d_nose - V);
            return true;
        case '2':
            Union = Union + 2*(d_nose - V);
            return true;
            // ----
        case '3':
            Union = Union + 3*(d_nose - V);
            return true;
        case '4':
            Union = Union + 4*(d_nose - V);
            return true;
            // ----
        case '5':
            Union = Union + 5*(d_nose - V);
            return true;
    }
    return false;
}



bool Morph::pre_draw(igl::opengl::glfw::Viewer& viewer_temp) {
    viewer_temp.data().set_vertices(Union);
    viewer_temp.data().compute_normals();
    return false;
}



void Morph::init_bones()
{
    // main face
    igl::readOBJ("C:\\Users\\user\\Desktop\\models\\face.obj", V, F);
    // cheeks
    igl::readOBJ("C:\\Users\\user\\Desktop\\models\\cheeks.obj", d_cheeks, F1);
    // chin
    igl::readOBJ("C:\\Users\\user\\Desktop\\models\\chin.obj", d_chin, F1);
    // horns
    igl::readOBJ("C:\\Users\\user\\Desktop\\models\\horns.obj", d_horns, F1);
    // jawls
    igl::readOBJ("C:\\Users\\user\\Desktop\\models\\jawls.obj", d_jawls, F1);
    // lips
    igl::readOBJ("C:\\Users\\user\\Desktop\\models\\lips.obj", d_lips, F1);
    // nose
    igl::readOBJ("C:\\Users\\user\\Desktop\\models\\nose.obj", d_nose, F1);
}



void Morph::save_file(std::string source) {
    igl::writeOBJ(source, Union, F);
}



void Morph::rounder(std::string source_input, std::string source_output) {
    // �������� ������ ��� ������ � ������
    Eigen::MatrixXd V_spec_for_rounder;
    Eigen::MatrixXi F_spec_for_rounder;


    // �������� �� ���������� �����.
    if (source_input.substr(source_input.size() - 3, 3) == "obj") {
        if (igl::readOBJ(source_input, V_spec_for_rounder, F_spec_for_rounder)) // ������ �����
        {
            // ����������
            for (int i = 0; i < V_spec_for_rounder.rows(); i++) {
                for (int j = 0; j < 3; j++) {
                    V_spec_for_rounder(i, j) = std::round(V_spec_for_rounder(i, j) * 10000) / 10000;
                }
            }
            if (igl::writeOBJ(source_output, V_spec_for_rounder, F_spec_for_rounder)) // ������ �����
            {
                std::cout << "\nRounder result: SUCCESS\n";
            }
            else std::cout << "\nRounder result: ERROR due writing obj\n";
        }
        else std::cout << "\nRounder result: ERROR due reading obj\n";
    }
        // �������� �� ���������� �����.
    else if (source_input.substr(source_input.size() - 3, 3) == "off")
    {
        if (igl::readOFF(source_input, V_spec_for_rounder, F_spec_for_rounder))
        {
            for (int i = 0; i < V_spec_for_rounder.rows(); i++) {
                for (int j = 0; j < 3; j++) {
                    V_spec_for_rounder(i, j) = std::round(V_spec_for_rounder(i, j) * 10000) / 10000;
                }
            }
            if (igl::writeOBJ(source_output, V_spec_for_rounder, F_spec_for_rounder))
            {
                std::cout << "\nRounder result: SUCCESS\n";
            }
            else std::cout << "\nRounder result: ERROR due writing obj\n";
        }
        else std::cout << "\nRounder result: ERROR due reading off\n";
    }
    else
    {
        std::cout << "ERROR: Input file type should be .obj or .off.";
    }
}



void Morph::convert_off_to_obj(std::string source_input, std::string source_output) {
    Eigen::MatrixXd V_spec_for_conv;
    Eigen::MatrixXi F_spec_for_conv;

    if (igl::readOFF(source_input, V_spec_for_conv, F_spec_for_conv))
    {
        if (igl::writeOBJ(source_output, V_spec_for_conv, F_spec_for_conv))
        {
            std::cout << "\nConvert result: SUCCESS\n";
        }
        else std::cout << "\nConvert result: ERROR due writing\n";
    }
    else std::cout << "\nConvert result: ERROR due reading\n";
}



void Morph::convert_obj_to_off(std::string source_input, std::string source_output) {
    Eigen::MatrixXd V_spec_for_conv;
    Eigen::MatrixXi F_spec_for_conv;

    if (igl::readOBJ(source_input, V_spec_for_conv, F_spec_for_conv))
    {
        if (igl::writeOFF(source_output, V_spec_for_conv, F_spec_for_conv))
        {
            std::cout << "\nConvert result: SUCCESS\n";
        }
        else std::cout << "\nConvert result: ERROR due writing\n";
    }
    else std::cout << "\nConvert result: ERROR due reading\n";
}



void Morph::write_obj(Eigen::MatrixXd V_input, Eigen::MatrixXi F_input, std::string source_output) {
    std::ofstream out;
    // "C:\\Users\\user\\Desktop\\test\\V3.txt"
    out.open(source_output);
    if (out.is_open())
    {
        out << V_input;
        out << "\n";
        out << F_input;
    }
    out.close();
    std::cout << "File has been written" << std::endl;
}



void Morph::fast_draw(std::string source_to_file) {

    igl::readOBJ(source_to_file, V, F);

    igl::opengl::glfw::Viewer viewer;
    viewer.data().set_mesh(V, F);
    viewer.launch();
}



void Morph::draw_mesh() {
    init_bones();
    Union = V;
    igl::opengl::glfw::Viewer viewer;
    viewer.data().set_mesh(Union, F);

    viewer.callback_key_down = [&](igl::opengl::glfw::Viewer& viewer_temp, unsigned int key, int mods) {
        return nose(viewer_temp, key);
    };

    viewer.callback_pre_draw = [&](igl::opengl::glfw::Viewer& viewer_temp) {
        return pre_draw(viewer_temp);
    };

    viewer.launch();
}
