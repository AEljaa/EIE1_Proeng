#include <iostream>

void perim_area(double len1,double len2,double& perim,double& area){
  perim=2*(len1+len2);
  area=len1*len2;
}

int main(){
  double len1,len2;
  double s1,s2;
  std::cout<<"Please Enter the Lengths of the perpendicular sides of the rectangle: "<<std::endl;
  std::cin>>len1>>len2;
  perim_area(len1,len2,s1,s2);
  std::cout<<"The Perimiter is :"<<s1<<std::endl;
  std::cout<<"The Area is :"<<s2<<std::endl;
}