#ifndef CAMERA_H
#define CAMERA_H
#include <Eigen/Geometry>

using namespace Eigen;
class Camera
{
private:
    Vector3f m_position;
    Quaternionf m_rotation;
    float m_fov;
    int m_pWidth, m_pHeight;
    /**
     * @brief lookAt change the direction of the camera toward positionObject. Not moving the camera
     * @param positionObject the position of the object
     */
    void lookAt(Vector3f positionObject);
public:
    Camera():m_fov(0),m_pWidth(0),m_pHeight(0){}
    Camera(Vector3f position, Vector3f direction, float fov, int pixelWidth, int pixelHeight);
    Camera(Vector3f position, Vector3f direction, float fov);


    /**
     * @brief move place the camera at the point newPosition
     * @param newPosition desired position
     */
    void move(Vector3f newPosition)    { m_position = newPosition; }

    /**
     * @brief translate modifies the position of the camera by translating it
     * @param translation the value of the translation
     */
    void translate(Vector3f translation)    {m_position += translation;}
    /**
     * @brief orientation
     * @return  quaternion describing the rotation
     */
    Quaternionf orientation()   {return m_rotation;}
    /**
     * @brief rotate modifies the rotation of the camera according to quaternion multiplication
     * @param rotation is the applied rotation to the already rotated camera
     */
    void rotate(Quaternionf rotation)   { m_rotation*=rotation;}
    //maybe create something that creates rays directly, easily...

    Camera& operator=(Camera& c)
    {
        m_position=c.m_position;
        m_rotation=c.m_rotation;
        m_fov=c.m_fov;
        m_pWidth=c.m_pWidth;
        m_pHeight=c.m_pHeight;
    }
};

#endif // CAMERA_H
