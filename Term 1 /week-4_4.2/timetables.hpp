#include <iostream>
int main(){
  int n;
  std::cout<<"How many rows and colums of the timebale"<<std::endl;
  std::cin>>n;
  for(int i=1;i<n+1;i++){
    for(int j=1;j<n+1;j++){
      std::cout<<j*i;
      std::cout<<"\t";
  }
    
    std::cout<<std::endl;
  }
 }