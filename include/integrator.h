#ifndef INTEGRATOR_H
#define INTEGRATOR_H
#include <Eigen/Geometry>
class Scene;
struct Ray;

using namespace Eigen;

class Integrator
{
public:
    virtual Vector3f Li(Scene& scene, Ray& ray) = 0;

};

class PathTracer
{
public:
    virtual Vector3f Li(Scene& scene, Ray& ray);
};
#endif // INTEGRATOR_H
