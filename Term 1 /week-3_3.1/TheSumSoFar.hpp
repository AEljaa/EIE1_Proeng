#include <iostream>

int main(){
  int User_num,Sum=0;
  std::cout<<"Enter a number: "<< std::endl;
  std::cin>>User_num;
  while(User_num != 0){
    std::cout<<"Enter another number: "<< std::endl;
    Sum+=User_num;
    std::cout<<"The sum so far is "<<Sum<<std::endl<<std::endl;
    std::cin>>User_num;
  }
}