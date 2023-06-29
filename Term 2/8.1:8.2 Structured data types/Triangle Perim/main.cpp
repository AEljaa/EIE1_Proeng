#include <iostream>
#include <cmath>
struct Point{
    double x;
    double y;
};
struct Triangle{
     Point a;
     Point b;
     Point c;
};

double triangle_perimeter(Triangle t){
    return std::sqrt(std::pow((t.a.x - t.b.x), 2) + std::pow(((t.a.y - t.b.y)), 2)) +std::sqrt(std::pow((t.a.x - t.c.x), 2) + std::pow(((t.a.y - t.c.y)), 2))+ std::sqrt(std::pow((t.b.x - t.c.x), 2) + std::pow(((t.b.y - t.c.y)), 2));

}

int main() {
    Triangle t;
    std::cout << "Please enter the X and Y coordinates of the 1st point of the triangle:" << std::endl;
    std::cin>>t.a.x>>t.a.y;
    std::cout << "Please enter the X and Y coordinates of the 2nd point of the triangle:" << std::endl;
    std::cin>>t.b.x>>t.b.y;
    std::cout << "Please enter the X and Y coordinates of the 3rd point of the triangle:" << std::endl;
    std::cin>>t.c.x>>t.c.y;

    std::cout<<triangle_perimeter(t)<<std::endl;

}
