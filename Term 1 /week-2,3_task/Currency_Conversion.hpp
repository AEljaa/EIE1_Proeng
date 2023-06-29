#include <iostream>

int main(){
  
  double UserMoney , Rate ;
  std::cout<< "What Amount of British Pounds would you like to convert to Euros?" << std::endl ;
  std:: cin >> UserMoney;

  std::cout <<" What is the Current Exchange Rate from Pounds to Euros? "<<std::endl;

  std::cin >> Rate ;

  double UserEuro = (UserMoney * Rate);

  std::cout << "The Value of your money in Euros is, " << UserEuro << std::endl ;
}