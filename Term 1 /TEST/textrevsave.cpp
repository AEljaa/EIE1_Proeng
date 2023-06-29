#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

void ReverseVec(const std::vector<double>& vin, std::vector<double>& vout){
  int size;
  size=vin.size()-1;
  
  
  for(int i=0;i<vin.size();i++){
    vout[i]=vin[size-i];
    std::cout<<vout[i]<<std::endl;
  }
  
}




int main(){
    std::ifstream infile; 
    infile.open("input.txt");
 
    std::vector<double> v,vout;
 
    if(!infile.is_open()){ 
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }
 
    int tmp;
 
    while(infile >> tmp){
        v.push_back(tmp); 
        // instead of printing the values
        // as in the example above
        // first we store them in a vector
    }
 
    infile.close(); 
    std::cout<<"Reversing Vector... : "<<std::endl;

    ReverseVec(v,vout);
    
    
    // TODO: print the content of v in reversed order
 
}