#ifndef TRIANGLEMESH_H
#define TRIANGLEMESH_H
#include "shape.h"
#include <Eigen/Geometry>
#include "vector.h"
using namespace Eigen;

class TriangleMesh : public Shape
{
// one TriangleMesh holds multiple surfaces
// one surface is one vector of 3 components
// one surface has one material

    std::vector<Vector3f> vertices;         // v
    std::vector<Vector3f> textureVertices;  // vt
    std::vector<Normal3f> normals;          // vn
std::vector< TriangleSurface > surfaces;
public:
    TriangleMesh();
};

#endif // TRIANGLEMESH_H
