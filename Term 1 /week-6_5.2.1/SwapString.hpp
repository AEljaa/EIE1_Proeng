#include <iostream>
#include <string>
void swap(std::string& word1,std::string& word2){
  std::string tempword;
  tempword=word1;
  word1=word2;
  word2=tempword;
}

int main(){
  std::string word1,word2;
  std::cout<<"Please Enter 2 words to swap: "<<std::endl;
  std::cin>>word1>>word2;

  std::cout<<"First word :"<<word1<<std::endl;
  std::cout<<"Second word :"<<word2<<std::endl;
  
  swap(word1,word2);

  std::cout<<"SWAPPED!!!"<<std::endl;
  
  std::cout<<"First word :"<<word1<<std::endl;
  std::cout<<"Second word :"<<word2<<std::endl;
  
}