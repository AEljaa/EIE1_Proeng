#include <iostream>

int main(){
  int top,bot,remainder,first,quotient=0;
  std::cout<<"Please enter you would like to divide: "<< std::endl;
  std::cin>>top;
  std::cout<<"Please enter you would like to divide "<< top <<" "<<"by: "<<std::endl;
  std::cin>>bot;
  remainder=top;
  while(bot<remainder){
    remainder-=bot;
    quotient+=1;
    
  }
  std::cout<<"The quotient  is "<<quotient<<" The remainder is "<< remainder << std::endl;
}