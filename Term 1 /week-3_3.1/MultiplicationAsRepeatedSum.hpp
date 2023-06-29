#include <iostream>;

int main(){
  int y,x,n,i=1 ;
  int sum,sum2 ;
  int j;
  y=x;
  
  std::cin>>x>>n;
  
  sum=n*x;
  while(i<n+1){
    x=x^i;
    i +=1;
  }

  j= x/y ;
 
  std::cout<<j<< std::endl;
}