#ifndef VECTOR_H
#define VECTOR_H
#include <sstream>
#include <Eigen/Geometry>



struct Normal3f : public Eigen::Matrix<float, 3, 1> {
public:
    enum {
        Dimension = 3
    };

    typedef float                               Scalar;
    typedef Eigen::Matrix<Scalar, Dimension, 1> Base;


    /// Create a new normal with constant component vlaues
    Normal3f(Scalar value = 0.0f) { Base::setConstant(value); }

    /// Create a new 3D normal
    Normal3f(Scalar x, Scalar y, Scalar z) : Base(x, y, z) { }

    /// Construct a normal from MatrixBase (needed to play nice with Eigen)
    template <typename Derived> Normal3f(const Eigen::MatrixBase<Derived>& p)
        : Base(p) { }

    /// Assign a normal from MatrixBase (needed to play nice with Eigen)
    template <typename Derived> Normal3f &operator=(const Eigen::MatrixBase<Derived>& p) {
        this->Base::operator=(p);
        return *this;
    }

    /// Return a human-readable string summary
    std::string toString() const {
        std::stringstream ss;
        ss<<"["<<coeff(0)<<", "<<coeff(1)<<", "<<coeff(2)<<"]";
        return ss.str();//tfm::format("[%f, %f, %f]", coeff(0), coeff(1), coeff(2));
    }
};

struct Color3f : public Eigen::Matrix<float,3,1> {
    typedef float Scalar;
    typedef Eigen::Matrix<Scalar,3,1>   Base;
    Color3f(Scalar value=0.f) {Base::setConstant(value);}
    Color3f(Scalar x=0.f, Scalar y=0.f, Scalar z=0.f):Base(x,y,z){}

    /// Construct a color from MatrixBase (needed to play nice with Eigen)
    template <typename Derived> Color3f(const Eigen::MatrixBase<Derived>& p)
        : Base(p) { }

    /// Assign a normal from MatrixBase (needed to play nice with Eigen)
    template <typename Derived> Color3f &operator=(const Eigen::MatrixBase<Derived>& p) {
        this->Base::operator=(p);
        return *this;
    }

    /// Return a human-readable string summary
    std::string toString() const {
        std::stringstream ss;
        ss<<"["<<coeff(0)<<", "<<coeff(1)<<", "<<coeff(2)<<"]";
        return ss.str();//tfm::format("[%f, %f, %f]", coeff(0), coeff(1), coeff(2));
    }
};

#endif // VECTOR_H
