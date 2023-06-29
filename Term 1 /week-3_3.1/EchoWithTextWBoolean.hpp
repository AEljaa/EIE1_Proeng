#include <iostream> 
#include <string>

int main(){
    std::string n;
 
    std::cin >> n;
 
    while(n != "STOP" && ( n!="stop" ) && (n!="Stop")){
        std::cout << n << std::endl;
        std::cin >> n;
    }

}
