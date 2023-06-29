#include <iostream>
#include <cmath>

double sop(double x, double y){
  double sum=0;
  for(int i=1;i<y+1;i++){
    sum+=std::pow(x,i);
  }
  return sum;
}

int main(){
  double base,power ;
  std::cout<<"Enter a base then an exponent: "<<std::endl;
  std::cin>>base>>power;
  std::cout<<"The Sum of Powers is : "<<sop(base,power)<<std::endl;
}