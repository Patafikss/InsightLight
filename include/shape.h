#ifndef SHAPE_H
#define SHAPE_H
#include "shape.h"
#include <vector>
#include <Eigen/Geometry>

using namespace Eigen;

class Shape
{
public:
    Shape();
};

class Surface
{
private:
    unsigned int materialId;
    unsigned int surfaceId;
public:
    unsigned int getSurfaceId(){return surfaceId;}
    unsigned int getMaterialId(){return materialId;}
    Surface();
};

class TriangleSurface : public Surface
{
private:
    std::vector<Vector3i> vertexIndices;
    std::vector<Vector3i> normalIndices;
    std::vector<Vector3i> textureIndices;
public:
    TriangleSurface();
};

class QuadSurface : public Surface
{
private:

    std::vector<Vector4i> vertexIndices;
    std::vector<Vector4i> normalIndices;
    std::vector<Vector4i> textureIndices;

public:
    QuadSurface();
};

#endif // SHAPE_H
