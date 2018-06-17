#ifndef RAY_H
#define RAY_H
#include <Eigen/Geometry>
using namespace Eigen;
#define INVALID_ID (unsigned int) -1
namespace inli
{

struct Ray
{
    Vector3f o;//origin
    Vector3f d;//direction
};

struct Hit
{
    Vector3f pos;
    Vector3f normal;
    Vector2f uv;
    unsigned int geomID = INVALID_ID;
    unsigned int primID = INVALID_ID;
};

}
#endif // RAY_H
