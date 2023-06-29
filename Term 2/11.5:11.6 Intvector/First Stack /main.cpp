#include <iostream>

typedef int stack_type;

struct StackLayer {
    stack_type val;
    StackLayer * next;
};

class Stack {

public:

    //constructor
    Stack(): top_layer(nullptr),size_s(0) {

    };

    Stack(const Stack & other): top_layer(other.top_layer),size_s(other.size_s) {

    };

    void push(stack_type e) {
        StackLayer * tmp;
        tmp = new StackLayer;
        tmp -> val = e;
        tmp -> next = top_layer;
        top_layer = tmp;
        size_s++;

    }
    int top() const {
        return top_layer -> val;
    }

    void pop() {
        top_layer = top_layer -> next;
        size_s--;

    }
    // TODO: implement the member functions (see the main)

    int size() const {
        return size_s;
    }

    // TODO: remember to add a destructor
    ~Stack() {
        std::cout << "BYE BEING DESTROYED RN" << std::endl;
        while(top_layer != nullptr) {
            pop();
        }

    }

    Stack & operator = (const Stack & other) {
        if (this != & other) {
            while (top_layer != nullptr) {
                pop();
            }

            StackLayer * current = other.top_layer;
            Stack tmp;
            while (current != nullptr) {
                tmp.push(current -> val);
                current = current -> next;
            }

            while (tmp.top_layer != nullptr) {
                push(tmp.top());
                tmp.pop();
            }
        }

        return * this;
    }

private:

    StackLayer * top_layer;
    int size_s;
    // you can add other member data if needed but do not defeat the purpose of the exercise
    // e.g. don't add a std::vector to store the elements of the stack...

};

// this is in order to test that const correctness is implemented
void test_stack_const_correctness(const Stack & s) {
    std::cout << "CORRECT ? " << s.top() << std::endl;
    std::cout << "CORRECT size ?" << s.size() << std::endl;
}

int main() {

    Stack s1;

    s1.push(1);
    s1.push(2);

    std::cout << s1.top() << std::endl;
    // should print 2

    s1.pop();

    std::cout << s1.top() << std::endl;
    // should print 1

    Stack s2(s1);

    s2.push(3);

    std::cout << s2.top() << std::endl;
    // should print 3

    std::cout << s2.size() << std::endl;
    // should print 2

    std::cout << s1.top() << std::endl;
    // should print 1

    s1 = s2;


    std::cout << s1.top() << std::endl;
    // should print 3

}