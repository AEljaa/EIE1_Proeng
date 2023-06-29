#include <iostream>
#include <string>
 
int main(){
 
    double length_in, length_out;
    std::string unit_in, unit_out;
  
    // we declare variables for the input and the output
    // the length is a number, the unit name is text
 
    const double mile_to_km = 1.609;
    // useful way to define constants
    std::cout <<" Please Enter the Distance :" << std::endl;
    std::cin >> length_in >> unit_in;
    // we don't print a prompt, we just read the input
 
    if(unit_in == "km"){
        unit_out = "mile";
        length_out = length_in / mile_to_km;
    }
    else if(unit_in =="miles" || (unit_in == "mile")){
        unit_out = "km";
        length_out = length_in * mile_to_km;
    }
 
    

    else{
    std::cout << "Error, unit not recognised, pleasm enter your values in either Km or miles" << std::endl ;
    }

    std::cout << length_out << " " << unit_out <<"s"<< std::endl ;
}
