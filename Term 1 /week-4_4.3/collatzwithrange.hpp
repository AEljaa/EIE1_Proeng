#include <iostream>
int main(){
  int orig,usernum,count=0,max,start,end;
  
  std::cout<<"Enter The number you would like to start the collatz conjecture at: "<<std::endl;
  std::cin>>start;
  std::cout<<"Enter The number you would like to end the collatz conjecture at: "<<std::endl;
  std::cin>>end;
  
  //for (/*initialize*/;/*condition*/;/*post loop code*/)
/*
  initialize
  while(condition)
  {
    // do stuff

    // end of loop code
 }
  */
  
  max = start;
  for (int i = start; i <= end; i++)
  {
    int target = i;
    
    
    while(target!=1){
      if(target%2==0){
        target /= 2;
        count++;
  
      }
      else{
        target=(3*target)+1;
        count++;
      }
      if(target>max){
        max=target;
      }
      
    }
    std::cout<<"Starting from "<<i<<" the number of steps to reach 1 is "<<count<<std::endl;
    std::cout << "The Maximum number generated was: " << max << std::endl;
    std::cout << "                                                " << std::endl;
    count=0;
    max=0;
  }
} 
