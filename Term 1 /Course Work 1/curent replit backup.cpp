#include<iostream>
#include<vector>
#include<fstream>
#include<cstdlib>
#include<string>

std::vector<int> string_to_digits(std::string s){
    std::vector<int> out; 
    for(int i = 0; i < s.size(); i++){
 
       std::string digit_string;
       digit_string.push_back(s[i]);
 
       int digit_int = std::stoi(digit_string);
 
       out.push_back(digit_int);
 
    } 
    return out;
}

bool possible_sequence(std::string round, std::string sequence){
  bool cond=true;
  std::vector<int> rndvec,seqvec;
  rndvec=string_to_digits(round);
  seqvec=string_to_digits(sequence);
  
  //checks to see if the size of the values inputed is less than or equal to the size of the round 

  if(rndvec.size()<=seqvec.size()){
    cond=false;
    return cond;  
  }
  //checks to see if there is a number in the sequnce vector that doesnt appear in the allowed vector list therefor allowin us to see if the value is valid
  
    for (const auto& i : seqvec) {
        bool found = false;
      
        for (const auto& j : rndvec){
            if (j == i){
                found = true;
                break;
            }
        }
      
        if (!found){
            // If we reach this point, it means that an element of v2 was
            // not found in v1, so we return false.
            cond=false;
        }
    
    }
return cond;
}


int score(std::string s,std::vector<std::string> valuesVec){
  std::vector<int> allowed,values;
  int sum=0;
  allowed=string_to_digits(s);
  for(int i=0;i<allowed.size();i++){
    values.push_back(5);
    }
  for(int i=0;i<allowed.size();i++){
    sum+=values[allowed[i]];
  }

  return sum;
  
}

int main(){
    std::string sequence,allow,round,value,outp,allowedstr,valuesstr,roundsstr; 
    std::vector<int> input,index;
    std::vector<std::string> allowedVec,roundsVec,valuesVec;
    int scores;
    std::ifstream allowed,rounds,values; 
    std::string line;
  
    std::cin>>allow;
    std::cin>>value;
    std::cin>>round;
    std::cin>>outp;
  
    allowed.open(allow);
    rounds.open(round);
    values.open(value);
 
 
     while (std::getline(allowed,line)){
      allowedVec.push_back(line); // Add the line to the vector
    }
      while (std::getline(rounds, line)){
      roundsVec.push_back(line); // Add the line to the vector
    }
      while (std::getline(values, line)){
      valuesVec.push_back(line); // Add the line to the vector
    }

    allowed.close(); 
    rounds.close();
    values.close();
  

  for(int i=0;i<roundsVec.size();i++){
    for(int j=0;j<allowedVec.size();j++){
      if(possible_sequence(roundsVec[i],allowedVec[j])){
          
          scores=score(allowedVec[j],valuesVec);
          
          std::cout<<" "<<std::endl;
          
          std::cout<<" "<<std::endl;
          std::cout<<"Played :" <<allowedVec[j]<<std::endl;
          
         
        }
      }
      
      int va=scores;
      
      std::cout<<"Round: "<< roundsVec[i]<<std::endl;
      std::cout<<"Score :"<<va<<std::endl;
      
    }


  

}
