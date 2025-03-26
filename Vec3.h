#include <iostream>
#include <math.h>

#ifndef vec
#define vec

class Vec3
{
    public:
    double e[3];

    Vec3():e{0,0,0}{}
    Vec3(double e0,double e1,double e2):e{e0,e1,e2}{}

    double x() const {return e[0];}
    double y() const {return e[1];}
    double z() const {return e[2];}

    Vec3 operator-() const {return Vec3(-e[0],-e[1],-e[2]);} //反向向量
    double operator[](int i) {return e[i];} //向量访问
    Vec3& operator+=(const Vec3 &v) //向量加法
    {
        e[0]+=v.e[0];
        e[1]+=v.e[1];
        e[2]+=v.e[2];
        return *this;
    }
    Vec3& operator-=(const Vec3 &v) //向量减法
    {
        return *this+=(-v);
    }
    Vec3& operator*=(const double i) //向量数乘
    {
        e[0]*=i;
        e[1]*=i;
        e[2]*=i;
        return *this;
    }
    Vec3& operator/=(const double i) //向量数除
    {
        return *this*=(1/i);
    }
    double Length() const //向量长度
    {
        return sqrt(LengthSquared());
    }
    double LengthSquared() const //向量长度的平方
    {
        return e[0]*e[0]+e[1]*e[1]+e[2]*e[2];
    }
    void write_color(std::ostream &out) {
        out << static_cast<int>(255.999 * e[0]) << ' '
            << static_cast<int>(255.999 * e[1]) << ' '
            << static_cast<int>(255.999 * e[2]) << '\n';
    }
};

inline std::ostream& operator<<(std::ostream &out, const Vec3 &v) //输出向量
{
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline Vec3 operator+(const Vec3 &v1,const Vec3 &v2) //向量相加
{
    return Vec3(v1.e[0]+v2.e[0],v1.e[1]+v2.e[1],v1.e[2]+v2.e[2]);
}

inline Vec3 operator-(const Vec3 &v1,const Vec3 &v2) //向量相减
{
    return Vec3(v1.e[0]-v2.e[0],v1.e[1]-v2.e[1],v1.e[2]-v2.e[2]);
}

inline Vec3 operator*(const Vec3 &v1,const Vec3 &v2) //向量点乘(返回向量)
{
    return Vec3(v1.e[0]*v2.e[0],v1.e[1]*v2.e[1],v1.e[2]*v2.e[2]);
}

inline Vec3 operator*(double t, const Vec3 &v) //向量数乘(数左向量右)
{
    return Vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline Vec3 operator*(const Vec3 &v,double t) //向量数乘(数右向量左)
{
    return t*v;
}

inline Vec3 operator/(const Vec3 &v, double t) //向量数除
{
    return (1/t) * v;
}

inline double dot(const Vec3 &v1,const Vec3 &v2) //向量点乘(返回数)
{
    return v1.e[0]*v2.e[0]+v1.e[1]*v2.e[1]+v1.e[2]*v2.e[2];
}

inline Vec3 cross(const Vec3 &v1,const Vec3 &v2) //向量叉乘
{
    return Vec3(v1.e[1]*v2.e[2]-v1.e[2]*v2.e[1],    //y1 * z2 - z1 * y2
                v1.e[2]*v2.e[0]-v1.e[0]*v2.e[2],    //z1 * x2 - x1 * z2
                v1.e[0]*v2.e[1]-v1.e[1]*v2.e[0]     //x1 * y2 - y1 * x2
                );   
}

inline Vec3 norm(Vec3 v) //向量归一化
{
    return v / v.Length();
}
#endif