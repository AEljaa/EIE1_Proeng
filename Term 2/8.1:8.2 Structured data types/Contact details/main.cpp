#include <iostream>
#include <string>
#include <vector>
#include <fstream>



struct Contact{
    std::string a;
    std::string b;
    std::string c;
    std::string d;

};

int search_contact(const std::vector<Contact>& contacts, std::string first_name, std::string surname){
    int ind=-1;
    for(int i=0;i<contacts.size();i++){
        if(first_name==contacts[i].a && surname==contacts[i].b){
            ind=i;
        }
    }
    return ind;


}

int main() {
    std::string first_name,surname;

    std::ifstream infile;
    infile.open("data.txt");

    if(!infile.is_open()){
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<Contact> details;
    Contact tmp;

    while(infile >> tmp.a >> tmp.b>> tmp.c>> tmp.d){
        details.push_back(tmp);
    }

    infile.close();

    std::cout<<"Please enter the name and surname of the person who's details you would like:"<<std::endl;
    std::cin>>first_name>>surname;
    int ind=search_contact(details,first_name,surname);
    if(ind==-1){
        std::cout<<"Contact not found"<<std::endl;
    }
    else{
        std::cout<<details[ind].a<<" "<<details[ind].b<<" "<<details[ind].c<<" "<<details[ind].d<<std::endl;
    }


}
