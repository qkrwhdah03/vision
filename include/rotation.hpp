#ifndef ROTATION_DEFINITIONS_H
#define ROTATION_DEFINITIONS_H

#include <Eigen/Core>
#include <Eigen/Geometry>

template <typename T> class Rotation3d{
    private:
        Eigen::Matrix<T, 3, 3> rotation;
    
    public:
        void setRotation(const Eigen::Matrix<T, 3, 3>& rotation_);
        void setRotation(const Eigen::AngleAxis<T>& angleaxis_);
        void setRotation(const Eigen::Quaternion<T>& quaternion_);
        
        Eigen::Matrix<T, 3, 1> rotate(Eigen::Matrix<T, 3, 1> &p);
};

#endif