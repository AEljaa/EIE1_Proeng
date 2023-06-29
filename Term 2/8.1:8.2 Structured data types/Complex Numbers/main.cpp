#include <iostream>
#include <cmath>
// for the square root
struct Comlexnum{
    double x;
    double y;
};
double compsol(double a, double b, double c, double& x1, double& x2){
    Comlexnum Sol;
    Sol.x=-b/2*a;
    Sol.y = (b*b - 4 * a * c)/2*a;
    if(Sol.y<0){
        std::cout << Sol.x<< Sol.y << "i" << std::endl;
    }
    std::cout << Sol.x << "+" << -Sol.y << "i" << std::endl;




}

bool quadsolve(double a, double b, double c, double& x1, double& x2){

    bool realsol;
    double delta = b*b - 4 * a * c;

    if(delta < 0){
        compsol(a, b, c,x1,x2);
    }
    else{

        realsol = true;
        x1 = (-b + std::sqrt(delta)) / (2 * a);
        x2 = (-b - std::sqrt(delta)) / (2 * a);

        // function sqrt computes the square root
        // more legible and sometimes more efficient
        // than using e.g. std::pow(delta, 0.5)

    }

    return realsol;
}

int main(){

    double a, b, c;
    // it is just a coincidence that these variables are named
    // like the function parameters, they could have a different name

    std::cout << "This program finds the real and complex solutions" << std::endl;
    std::cout << "Of an equation of the form ax^2 + bx + c = 0" << std::endl;
    std::cout << "Please enter the coefficients a, b, c:" << std::endl;

    std::cin >> a >> b >> c;

    double s1, s2;
    // we pass these variables uninitialised to the function
    // because the values will be provided in output
    // by the function

    if(quadsolve(a, b, c, s1, s2)){
        std::cout << "the solutions are:" << std::endl;
        std::cout << s1 << std::endl;
        std::cout << s2 << std::endl;
    }


}