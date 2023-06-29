#include<iostream>

int main(){
  int year;
  std::cout<<"Please Enter a year: "<<std::endl;
  std::cin>>year;
  if((year % 400==0 || year % 100!=0) && year%4==0){
    std::cout<<"Leap year!!!"<<std::endl;
    }
  else{
    std::cout<<"No leap year :("<<std::endl;
    }
  
}