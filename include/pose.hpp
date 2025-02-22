#ifndef POSE_DEFINITIONS_H
#define POSE_DEFINITIONS_H

#include <vector>
#include <eigen/core>

template <typename T> class Pose3d{
    private:
        Eigen::Matrix<T, 3, 3> rotation; // 3x3 rotation matrix
        Eigen::Matrix<T, 3, 1> translation; // 3x1 translation vector
    
    public:
    // Setting Values
       void setRotation(const Eigen::Matrix<T, 3, 3>& rotation_ );
       void setTranslation(ocnst Eigen::Matrix<T, 3, 1>& translation_);

    // Extraction
        Eigen::Matrix<T, 3, 3> getRotationMatrix();
        Eigen::Matrix<T, 3, 1> getTranslationVector();
        Eigen::Matrix<T, 4, 3> getTransformationMatrix();    
    
    // Transformation
       Eigen::Matrix<T, 3, 1> transform(const Eigen::Matrix<T, 3, 1>& point);
};

#endif
