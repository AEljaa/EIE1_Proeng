#include <iostream>
 
int main(){
    double n1, n2, product;
    // this line declares three variables of a numerical type
    // n1, n2, sum are the names of the variables
    // double is the type, which represents general decimal numbers
 
    std::cout << "please enter the first number" << std::endl;
    std::cin >> n1;
 
    std::cout << "please enter the second number" << std::endl;
    std::cin >> n2;
 
    product = n1 * n2;
    // here the result of n1 + n2 is computed
    // and it is stored in variable product
 
    std::cout << n1 << " x " << n2 << " = " <<  product << std::endl;
    // this is a printing instruction printing
    // the value in n1
    // the symbol + (with spaces)
    // the value in n2
    // the symbol = (with spaces)
    // the value in product
    // (and a newline at the end as usual)
}