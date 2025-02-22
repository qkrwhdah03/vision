#include "rotation.hpp"

template <typename T> 
void Rotation3d<T>::setRotation(const Eigen::Matrix<T, 3, 3>& rotation_){
    this->rotation = rotation_.eval();
}

template <typename  T>
void Rotation3d<T>::setRotation(const Eigen::AngleAxis<T>& angleaxis_){
    this->rotation = angleaxis_.toRotationMatrix();
}

template <typename T>
void Rotation3d<T>::setRotation(const Eigen::Quaternion<T>& quaternion_){
    this->rotation = quaternion_.toRotationMatrix();
}

template <typename T>
Eigen::Matrix<T, 3, 1> Rotation3d<T>::rotate(Eigen::Matrix<T, 3, 1>& p){
    return this->rotation * p;
}

template class Rotation3d<double>;
template class Rotation3d<float>;