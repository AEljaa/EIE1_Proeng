#include <iostream>>

int main(){
  int side1,side2 ;
  std::cout << "What is the length of the first side of the rectangle?" << std::endl;

  std::cin >> side1;

  std::cout <<"What is the length of the second side of the rectangle?" << std::endl ;

  std::cin >> side2;

  int perimeter= 2*(side1 + side2);

  int area = side1 * side2 ;

  std::cout << "The perimeter of the rectangle is " << perimeter << " The area of the Rectangle is "<< area << std::endl;  

  
}