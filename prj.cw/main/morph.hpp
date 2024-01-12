//
// Created by Katya on 11.01.2024.
//

#ifndef TEST_MORPH_H
#define TEST_MORPH_H

#endif //TEST_MORPH_H

#include <iostream>

// std
#include <string>
#include <fstream>
#include <sstream>
#include <functional>

// readers
#include <igl/readOBJ.h>
#include <igl/readOFF.h>
#include <igl/readDMAT.h>

// writers
#include <igl/writeOBJ.h>
#include <igl/writeOFF.h>

//other
#include <igl/harmonic.h>
#include <igl/opengl/glfw/Viewer.h>
#include <igl/colon.h>


/// <summary>
/// \brief Work with 3d models. Morhp surfaces and view changes.
/// </summary>
class Morph
{
private:
    Eigen::MatrixXd
    /// \param V Matrix of vertices of the main model
    V,
    /// \param Union Matrix of vertices of the modified model. Used in the draw_mesh method.
    Union;
    Eigen::MatrixXd
    /// \param d_nose Matrix of nose vertices
    d_nose,
    /// \param d_chin Matrix of chin vertices
    d_chin,
    /// \param d_cheeks Matrix of cheeks vertices
    d_cheeks,
    /// \param d_jawls Matrix of jawls vertices
    d_jawls,
    /// \param d_lips Matrix of lips vertices
    d_lips,
    /// \param d_horns Matrix of horns vertices
    d_horns;
    Eigen::MatrixXi
    /// \param F Matrix of surfaces of the main model
    F,
    /// \param F1 Matrix of surfaces where surfaces of additional files
    /// (e.g. nose, cheeks) will be stored. This variable is not used,
    /// but it is mandatory because surfaces must be read.
    F1;



    /// \brief Reads keyboard input and calls corresponding changes in the face shape.
    bool nose(igl::opengl::glfw::Viewer& viewer_temp, unsigned int key);


    bool pre_draw(igl::opengl::glfw::Viewer& viewer_temp);


    /// \brief Reads data from additional files. Necessary for face editing mode.
    /**
    * Reads data from OBJ files and stores it in matrices.
    * Pay attention to the paths of the files being read inside the function.
    */
    void init_bones();


    /// \brief Saves a file with the .obj extension
    /**
    * Writes a 3D model to a file using the Union and F matrices.
    * This method is called after modifying the model, if you want to save the changes made.
    * Pay attention to the address where the file will be saved inside the function.
    */
    /// \param source String containing the address and name of the file to be saved.
    void save_file(std::string source);


public:


    Morph();



    /// \brief Rounds to four decimal places. Works only with OFF or OBJ files.
    /**
    * The algorithm: checks the file extension -> calls the read function -> rounds -> writes.
    */
    ///  \param source_input The address of the file to be processed.
    ///  \param source_output The address where the processed file will be saved.
    /// The address must contain the file name.
    void rounder(std::string source_input, std::string source_output);



    /// \brief Converts a file from off to obj. There is a similar function that
    /// converts from obj to off.
    /// \param source_input The address of the file to be processed.
    /// \param source_output The address where the processed file will be saved.
    /// The address must contain the file name.
    void convert_off_to_obj(std::string source_input, std::string source_output);



    ///  Converts a file from obj to off. There is a similar function that
    /// converts from off to obj.
    /// \param source_input The address of the file to be processed.
    /// \param source_output The address where the processed file will be saved.
    /// The address must contain the file name.
    void convert_obj_to_off(std::string source_input, std::string source_output);



    /// \brief Writes data from vertex and side matrices to a file
    /// \param V_input Matrix of vertices.
    /// \param F_input Matrix of sides.
    /// \param The address where the resulting file will be saved.
    void write_obj(Eigen::MatrixXd V_input, Eigen::MatrixXi F_input, std::string source_output);



    /// \brief  Launches the 3D model viewing mode. Does not allow editing of the face.
    /// \param source_to_file The address of the file to be read.
    /// Accepts obj or off files.
    void fast_draw(std::string source_to_file);


    /// \brief Launches the 3D model viewing mode. Allows editing the face.
    /// For correct operation, additional files must also be read - run the init_bones() function
    void draw_mesh();
};
