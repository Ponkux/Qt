#ifndef CONVERT_H
#define CONVERT_H

#include <cmath>

typedef struct{
    double yaw;
    double roll;
    double pitch;
}euler;

typedef struct{
   double x;
   double y;
   double z;
   double w;
}quaternion;

class convert
{
public:
    convert();
    void seteuler(double yaw,double pitch,double roll);
    bool setq(double x,double y,double z,double w);
    void convert2q();
    void convert2euler();
    euler angle;
    quaternion q;
};

#endif // CONVERT_H
