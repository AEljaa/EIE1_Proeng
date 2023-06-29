#include <iostream> // include a header file that provides input/output functionality

class SomeClass{ // define a class called SomeClass

public: // declare public members of the class

    SomeClass(int idinput) : id(idinput) { // define a constructor that takes an int parameter and initializes the id attribute with it
        std::cout << "object with id " << id << " instantiated" << std::endl; // print a message to the standard output stream
    }

    // define an assignment operator that takes a const reference to an object of the same class and assigns its id attribute to the current object
    SomeClass& operator=(const SomeClass& s){

        std::cout << "assignment operator" << std::endl;

        id = s.id;

        return *this;
        // return a reference to the current object to allow chaining of assignments
    }

    int get_id() const { // define a getter method that returns the value of the id attribute
        return id;
    }

private: // declare private members of the class

    int id; // declare an int attribute called id

};

int main(){
    SomeClass s1(1);
    SomeClass s2(2);
    SomeClass s3(3);

    std::cout << "s1: " << s1.get_id() << std::endl;
    std::cout << "s2: " << s2.get_id() << std::endl;
    std::cout << "s3: " << s3.get_id() << std::endl;

    s3.operator=( s2.operator=( s1 ) );
    // chained assignments
    // that can be used instead of writing:
    // s2 = s1;
    // s3 = s2;

    std::cout << "s1: " << s1.get_id() << std::endl;
    std::cout << "s2: " << s2.get_id() << std::endl;
    std::cout << "s3: " << s3.get_id() << std::endl;
}