#include<iostream>

const int height=200;   //图片的高
const int width=200;    //图片的宽

int main()
{
    std::cout << "P3\n" << width << ' ' << height << "\n255\n";
    for(int j=0;j<height;j++)
    {
        std::clog << "\rScanlines remaining: " << (height - j) << ' ' << std::flush;
        for(int i=0;i<width;i++)
        {
            double r=double(i)/width;
            double g=double(j)/height;
            double b=0.0;
            int ir=(int)(255.999*r);
            int ig=(int)(255.999*g);
            int ib=(int)(255.999*b);
            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
    std::clog << "\rDone.                 \n";
}