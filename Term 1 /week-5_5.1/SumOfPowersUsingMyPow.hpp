#include <iostream>
#include <cmath>

double mypow(double base, int exp){
    double result=1; 
    if(exp>0){
      for(int i=0;i<exp;i++){
        result=result*base;
      }
    }
  
    if(exp==0){
      result=1;
    }

    if(exp<0){
      for(int i=1;i<(-exp);i++){
      result=base*base;
      }
      result=1/result;
    }
  return result;
}


double sop(double base, int power){
  double sum=0;
  for(int i=0;i<power+1;i++){
    sum+=mypow(base,i);
  }
  return sum;
  
}

int main(){
  double base,power ;
  std::cout<<"Enter a base then an exponent: "<<std::endl;
  std::cin>>base>>power;
  std::cout<<"The Sum of Powers is : "<<sop(base,power)<<std::endl;
}