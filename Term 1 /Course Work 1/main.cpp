#include<iostream>
#include<vector>
#include<fstream>
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

  for(int i =0;i<seqvec.size();i++){
    int countseq=0,countrnd=0;
    int num=seqvec[i];
    for(int j=0;j<seqvec.size();j++){
      if(num==seqvec[j]){
        countseq++;
      }
    }
    for(int k=0;k<rndvec.size();k++){
      if(num==rndvec[k]){
        countrnd++;
      }
    }

    if(countseq > countrnd || countseq==0 || countrnd==0){
    cond=false;
    return cond;
    }
  }

return cond;
}


int score(std::vector<int> allowed,std::vector<int> valuesVec,std::vector<int>&bestscore){
  std::vector<int>values,conseq;
  int sum=0,conseqsum=0,zeroeror=0;

  for(int i=0;i<allowed.size();i++){

      if(allowed[i]+1==allowed[i+1] && (i+1)!=allowed.size()){
        conseq.push_back(allowed[i]);
        conseq.push_back(allowed[i+1]);

      //sum+=(valuesVec[allowed[i]] + valuesVec[allowed[i+1]])*2;
      }

    sum+=valuesVec[allowed[i]];
   }
  //minuses the incorrect values
  //and prevents any errors when 0 appears
  for(int i=0;i<conseq.size();i++){
    sum-=valuesVec[conseq[i]];
    conseqsum+=valuesVec[conseq[i]];
    if(6==conseq[i]){
      zeroeror++;
    }
  }


  conseqsum=conseqsum*(conseq.size()-zeroeror);

  for(int i=0;i<allowed.size();i++){
  }
  sum=sum+conseqsum;
  values.push_back(sum);
  return sum;


}

int main(){
    std::string sequence,allow,round,value,outp,allowedstr,valuesstr,roundsstr;
    std::vector<int> input,index,bestvalues;
    std::vector<std::string> allowedVec,roundsVec;
    std::vector<int> allowedVecint,roundsVecint,valuesVec;
    int scores,tmp;
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


    while(values >> tmp){
        valuesVec.push_back(tmp);
    }
    std::ofstream outfile;
     outfile.open("output.txt");



    allowed.close();
    rounds.close();
    values.close();





    //iterates through all rounds for each allowed value
  for(int i=0;i<roundsVec.size();i++){
    for(int j=0;j<allowedVec.size();j++){
            //if the allowed value sequence is allowed then a score is calculated for the allowed value
      if(possible_sequence(roundsVec[i],allowedVec[j])){
          outfile <<roundsVec[i]<<" "<< std::endl;
          allowedVecint.clear();
          allowedVecint=string_to_digits(allowedVec[j]);

          scores=score(allowedVecint,valuesVec,bestvalues);

          std::cout<<roundsVec[i]<<" "<<allowedVec[j]<<" "<< scores <<std::endl;
          outfile <<roundsVec[i]<<" "<<allowedVec[j]<<" "<< scores <<std::endl;



        }
      }



    }



outfile.close();
}