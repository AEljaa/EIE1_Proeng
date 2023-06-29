#include <iostream>
int main(){
  int n;
  std::cout<<"Please Enter How many rows and colums of stars you want"<<std::endl;
  std::cin>>n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      std::cout<<"*";
  }
    std::cout<<std::endl;
  }
}