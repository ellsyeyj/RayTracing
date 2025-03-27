#include <iostream>
#include "Vec3.h"
#include "Ray.h"

const int height=200;   //图片的高
const int width=400;    //图片的宽

bool HitSphere(const Vec3 &center,double radius,const Ray &r)
{
    Vec3 origin_center=r.origin()-center;
    double b=2*dot(origin_center,r.direction());
    double a=dot(r.direction(),r.direction());
    double c=(dot(origin_center,origin_center)-radius*radius);
    return (b*b-4*a*c)>0;
}

Vec3 ray_color(const Ray& r) { //根据y值决定颜色，y值越小越倾向于白色(255,255,255)，越大越倾向蓝色
    if(HitSphere(Vec3(0,0,-5),1,r))
    {
        return Vec3(1,0,0);
    }
    Vec3 unit_direction = norm(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*Vec3(1.0, 1.0, 1.0) + t*Vec3(0.5, 0.7, 1.0);
}

int main()
{
    //摄像机视角定义
    Vec3 low_left(-2,-1,-1);
    Vec3 vertical(0,2,0);
    Vec3 horizontal(4,0,0);
    Vec3 origin(0,0,0);
    std::cout << "P3\n" << width << ' ' << height << "\n255\n";
    //图片从左上往右写
    for(int j=height-1;j>=0;j--)
    {
        std::clog << "\rScanlines remaining: " << j << ' ' << std::flush;
        for(int i=0;i<width;i++)
        {
            Vec3 dir=low_left+((double)i/width)*horizontal+((double)j/height)*vertical;
            Ray r(origin,dir);
            Vec3 color=ray_color(r);
            color.write_color(std::cout);
        }
    }
    std::clog << "\rDone.                 \n";
}