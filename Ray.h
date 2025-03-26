#include "Vec3.h"

class Ray
{
public:
    Vec3 ori; //原点
    Vec3 dir; //方向

    Ray(){}
    Ray(const Vec3 &origin,const Vec3 &direction):ori(origin),dir(direction){}

    Vec3 origin() const {return ori;}
    Vec3 direction() const {return dir;}

    Vec3 at(double t) const //以t为变量获取该条直线(y=ori+t*dir)上的点
    {
        return ori+t*dir;
    }
};