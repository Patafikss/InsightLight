#ifndef OBJECTS_H
#define OBJECTS_H

#include <iostream>
#include <vector>
#include <tiny_obj_loader.h>
#include <Eigen/Geometry>

using namespace Eigen;

class Objects
{
private:
    std::string m_filename;
    tinyobj::attrib_t m_attrib;
    std::vector<tinyobj::shape_t> m_shapes;
    std::vector<tinyobj::material_t> m_materials;
    std::vector<Matrix4f> m_transformations;
public:
    //Objects();
    Objects(const std::string &objFile, const std::string &mtlDirectory);
    loadObject(const std::string &objFile, const std::string &mtlDirectory);
};

#endif // OBJECTS_H
