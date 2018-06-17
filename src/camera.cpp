#include "camera.h"
#include <Eigen/Geometry>
using namespace Eigen;

Camera::Camera(Vector3f position, Vector3f direction, float fov, int pixelWidth, int pixelHeight)
    :m_position(position),m_fov(fov),m_pWidth(pixelWidth),m_pHeight(pixelHeight)
{

}

Camera::Camera(Vector3f position, Vector3f direction, float fov)
    :m_position(position),m_fov(fov)
{

}
void Camera::lookAt(Vector3f positionObject)
{

}
