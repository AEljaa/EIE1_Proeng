#include <iostream>

int sort_num(int& n1,int& n2){
  int temp;
  temp=n2;
  if(n2>temp){
    n2=n1;
    n1=temp;
  }
}
void division(int& n1,int& n2,int& q,int& r){
  sort_num(int n1 ,int n2);
  q=n1/n2;
  int temp;
  temp=n2;
  if((n1%n2)==0){
    r=0;
  }
   else{
    r=temp-(q*n2);
  }
}

int main(){
  int n1,n2,qoutient,remainder;
  std::cout<<"Please enter two integer numbers: "<<std::endl;
  std::cin>>n1>>n2;
  division(n1,n2,qoutient,remainder);
  if(remainder==0){
    std::cout<<n1<<" = "<<n2<<" * "<<qoutient<<std::endl;
    }
  else{
    std::cout<<n1<<" = "<<n2<<" * "<<qoutient<<" + "<<remainder<<std::endl;
  }
  
}