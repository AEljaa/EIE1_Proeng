#include <iostream>

int main() {
  double n, absv;
  // n for the input, absv will be
  // the absolute value we compute
  std::cout << "Enter a number" << std::endl;
  // TODO: ask for a number in input
  // TODO: read the input number in n
  std::cin >> n;

  if (n < 0) { // yes/no question: is n less than 0?
    // if yes, its absolute value is the number changing the sign
    absv = -n;
  } 
  
  else {
    // if not, its absolute value is the same as n
    // TODO: assign the value of n to absv
    absv = n;
  }

  std::cout << "|" << n << "| = " << absv << std::endl;
}