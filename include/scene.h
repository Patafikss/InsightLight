#ifndef SCENE_H
#define SCENE_H
#include <iostream>
#include <vector>
#include <Eigen/Geometry>
#include <memory>
#include "objects.h"

using namespace Eigen;

class Scene
{
private:
//each object is an instance loaded by tinyobjloader
    std::vector<Objects> objects;
    void loadObjects(const std::string path, const std::string mtlPath);
public:
    Scene();
    Scene(const std::string file);
    void loadScene(const std::string file);
};

#endif // SCENE_H
