#include <iostream>
int main(){
  int userin,max,min;
  
  std::cout<<"Enter a number, Enter 0 to terminate"<<std::endl;
  
  std::cin>>userin;
  max=userin;
  min=userin;
  
  
  std::cout << "maximum so far: " << max << std::endl;
  std::cout << "minimum so far: " << min << std::endl;

  
  while(userin!=0){
    std::cout<<"Enter a number, Enter 0 to terminate"<<std::endl;
    std::cin>>userin;
    
    
    if(userin>max){
      max=userin;
      
    }

    if(userin<min){
      min=userin;
      
    }
    std::cout << "maximum so far: " << max << std::endl;
    std::cout << "minimum so far: " << min << std::endl;
    
  }
}