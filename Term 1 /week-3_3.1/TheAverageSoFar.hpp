#include <iostream>

int main(){
  double User_num,Sum=0,count=0;;
  double Average;
  std::cout<<"Enter a number: "<< std::endl;
  std::cin>>User_num;
  while(User_num != 0){
    std::cout<<"Enter another number: "<< std::endl;
    Sum+=User_num;
    count =count+1;
    Average=Sum/count;
    std::cout<<"The average so far is "<<Average<<" "<<count<< std::endl<<std::endl;
    std::cin>>User_num;

  }
}