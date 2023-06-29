#include <iostream>

int main(){
  double tempDeg,tempFar;
  std::cout << "What is the Current Temperature in Degrees? " << std::endl ;

  std::cin >>tempDeg ;
  tempFar= (tempDeg * 9/5 + 32 );

  std::cout << "The temperature in Fahrenheit is, " << tempFar << std::endl ;
    
}