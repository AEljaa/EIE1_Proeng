#include <iostream>
int main(){
  
  double base, power;
  int exponent;
  std::cout<<"Please enter the Base then the exponent"<<std::endl;
  std::cin >>base >> exponent;
  power=1;
  
  for(int i=1;i<exponent+1;i++){
    
    power=power*base;
    std::cout<<power<<" "<<i<<" "<<base<<std::endl;
  }

  
  
}

/*2 * 2 * 2

acc = acc * 2
  */
