#include <iostream>

int main(){
  int start,end,x,cond=2,userin,y,z;
  std::cout<<"Tell me the smallest number in the range of possible numbers"<<std::endl;
  std::cout<<"Tell me the biggest number in the range of possible numbers"<<std::endl;
  std::cin>>start>>end;
  if((end-start)%2==0){
    x=(start+end)/2;
  }
  else{
    x=(start+end+1)/2;
  }
  
  
  while(cond!=1){


    std::cout<<"Is your number Less than? "<<x<<" Press 1 for yes and 2 for no : " <<std::endl;
    std::cout<<start<<" "<<end<<std::endl;
    std::cin>>userin;
    if(userin==2){
      y=x;
      x=(end+x)/2;
      start=y;
      
    }
      
    else{
      z=x;
      x=(start+x)/2;
      end=z;
      
    }
    std::cout<<"YOUR NUMBER IS ... "<<x<<" !!!"<<std::endl;
    std::cout<<"Have I guessed correctly? Press 1 for yes, 2 for no "<<std::endl;
    std::cout<<start<<" "<<end<<std::endl;
    std::cin>>cond;
  }
}