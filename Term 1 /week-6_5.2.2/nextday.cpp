#include <iostream>
 
bool leap_year(int y1){
    bool ly;
 
    if(y1 % 400==0 || y1 % 100!=0 && y1%4==0){
      ly=true;
    }
    else{
      ly=false;
    }
    return ly;
}
 
void next_date(int d1, int m1, int y1, int& d2, int& m2, int& y2){
  bool ly;
  ly=leap_year(y1);
  d1=d1+1;
  m2=m1;
  y2=y1;
  d2=d1;
    
  if((m1==1||m1==3||m1==5||m1==7||m1==8||m1==10)&&(d1==32)){

    d2=1;
    m2=m1+1;
    y2=y1;
  }
  if((m1==4||m1==6||m1==9||m1==11||m1==12)&&(d1==31)){
    d2=1;
    m2=m1+1;
    y2=y1;
    
  }
  if((m1==2 && (ly==1) && d1==29)){
    d2=29;
    m2=m1;
    y2=y1;
  }

  if((m1==2 && (ly==0) && d1==29)){
    d2=1;
    m2=m1+1;
    y2=y1;
  }
  if((m1==2 && (ly==1) && d1==30)){
    d2=1;
    m2=m1+1;
    y2=y1;
  }

  if((m1==2 && (ly==0) && d1==29)){
    d2=1;
    m2=m1+1;
    y2=y1;
  }
  if(m1==12 && d1==32){
    d2=1;
    m2=1;
    y2=y1+1;
  }

}
 
int main(){
  int d1,m1,y1,d2,m2,y2;
  int s1,s2,s3;
  std::cout<<"Please enter the day month and year in DD MM YYYY format: "<<std::endl;
  std::cin>>d1>>m1>>y1;
  next_date(d1,m1,y1,s1,s2,s3);
  std::cout<<"The next daty is : "<<s1<<" "<<s2<<" "<<s3<<std::endl;
  
    // TODO: write a main that reads a date from the user,
    // calls function next_date to compute the date 
    // corresponding to the next day, and then prints it
}