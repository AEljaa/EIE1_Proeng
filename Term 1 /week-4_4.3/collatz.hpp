#include <iostream>
int main(){
  int orig,usernum,count=0,max;
  std::cout<<"Enter The number you would like to start the collatz at: "<<std::endl;
  std::cin>>usernum;
  
  max=usernum;
  orig=usernum;
  while(usernum!=1){
    if(usernum%2==0){
      usernum=usernum/2;
      count+=1;

    }
    else{
      usernum=(3*usernum)+1;
      count+=1;
    }
    if(usernum>max){
      max=usernum;
    }
    
  }
  std::cout<<"Starting from "<<orig<<" the number of steps to reach 1 is "<<count<<std::endl;
  std::cout << "The Maximum number generated was: " << max << std::endl;
} 
