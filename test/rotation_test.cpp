#include "rotation.hpp"
#include <iostream>

#define M_PI 3.14159265358979323846

using namespace std;

int main( int argc, char ** argv){

    Rotation3d<double> rotation;
    Eigen::AngleAxis<double> angleaxis(M_PI /4, Eigen::Vector3d::UnitZ());
    rotation.setRotation(angleaxis);

    Eigen::Vector3d p(1, 0, 0);
    Eigen::Vector3d rotated_p = rotation.rotate(p);
    
    cout << "Rotated Point : " << rotated_p.transpose() << endl;
    return 0;
}