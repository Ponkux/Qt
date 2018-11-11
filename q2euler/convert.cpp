#include "convert.h"

convert::convert()
{

}

void convert::seteuler(double yaw,double pitch,double roll){
    angle.yaw = yaw * M_PI / 180.0;
    angle.pitch = pitch * M_PI / 180.0;
    angle.roll = roll * M_PI / 180.0;
}

bool convert::setq(double x,double y,double z,double w){
    double _sqrt = sqrtf(x*x + y*y + z*z + w*w);
    if(fabs(_sqrt - 1) < 0.01){
        q.x = x;
        q.y = y;
        q.z = z;
        q.w = w;
        return true;
    }else{
        q.x = x / _sqrt;
        q.y = y / _sqrt;
        q.z = z / _sqrt;
        q.w = w / _sqrt;
        return false;
    }
}

void convert::convert2q(){
    double sinyaw  = sin(angle.yaw*0.5);
    double cosyaw  = cos(angle.yaw*0.5);
    double sinpit  = sin(angle.pitch*0.5);
    double cospit  = cos(angle.pitch*0.5);
    double sinroll = sin(angle.roll*0.5);
    double cosroll = cos(angle.roll*0.5);

    q.w = cosyaw * cospit * cosroll + sinyaw * sinpit * sinroll;
    q.x = sinyaw * cospit * cosroll - cosyaw * sinpit * sinroll;
    q.y = cosyaw * sinpit * cosroll + sinyaw * cospit * sinroll;
    q.z = cosyaw * cospit * sinroll - sinyaw * sinpit * cosroll;
}

void convert::convert2euler(){
    angle.yaw   = atan2(2*(q.w*q.x + q.y*q.z),1-2*(q.x*q.x + q.y*q.y)) * 180.0 / M_PI;
    angle.pitch = asin(2*(q.w*q.y - q.z*q.x)) * 180.0 / M_PI;
    angle.roll  = atan2(2*(q.w*q.z + q.x*q.y),1-2*(q.y*q.y + q.z*q.z)) * 180.0 / M_PI;
}
