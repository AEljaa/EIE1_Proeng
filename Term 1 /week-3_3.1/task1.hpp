#include <iostream>
 
int main(){
    int n, i = 0;
    // we have a variable counter
    // counting how many times we print
    // initially we have printed 0 times
 
    std::cin >> n;
 
    // the following line begins a while loop
    // the while loop has a condition in parentheses,
    // if the condition is true, then we enter the loop 
    // and execute the instructions inside
    // otherwise the execution goes past the loop
 
    while(i < n){
 
        std::cout << "hello" << std::endl;
 
        i += 1;
        // after each print we increase 
        // the counter by 1
    }
}