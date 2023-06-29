#include <iostream>
#include <string>

int main(){
  double Temp_in,Temp_out;
  std::string Unit_in, Unit_out;
  bool  valid_unit=true;
  std::cout <<"Please enter the temperature Followed by its units (C or F)" << std::endl ;
  
  std::cin >> Temp_in >> Unit_in;

  if(Unit_in=="C" || (Unit_in =="c")){
    Unit_out="F";
    Temp_out=((Temp_in * 9/5) + 32);
  }
  else if(Unit_in=="F" || (Unit_in =="f")){
    Unit_out="C";
    Temp_out=((Temp_in -32) *5/9);
  }
  else{
    valid_unit= false ;

    std::cout << "Error, " << Unit_in << " unit not recognised" << std::endl;
    }
  if(valid_unit){
    std::cout << "The temperature is " << Temp_out << Unit_out << std::endl;
    }
}