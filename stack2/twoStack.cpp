#include<iostream>
#include<limits.h>
using namespace std;

class stack{
    public:
    int *arr;
    int size;
    int top1;
    int top2;

    stack(int size){
        this->size = size;
        arr = new int[this->size];
        this->top1 = -1;
        this->top2 = this->size;
    }

    bool isFull(){
        if (this->top2-this->top1==1)
        {
            return true;
        }
        return false;
    }

    bool isempty1(){
        if (this->top1==-1)
        {
            return true;
        }
        return false;
    }

    bool isempty2(){
        if (this->top2==this->size)
        {
            return true;
        }
        return false;
    }

    void push1(int data){
        if (this->isFull())
        {
            return;
        }
        
        this->top1++;
        arr[top1] = data;
    }

    void push2(int data){
        if (this->isFull())
        {
            return;
        }
        this->top2--;
        arr[top2] = data;
    }

    void pop1(){
        if (this->isempty1())
        {
            return;
        }
        
        this->top1--;
    }

    void pop2(){
        if (this->isempty2())
        {
            return;
        }
        
        this->top2++;
    }

    int top1_element(){
        if (this->isempty1())
        {
            return INT_MIN;
        }
        
        return this->arr[this->top1];
    }

    int top2_element(){
        if (this->isempty2())
        {
            return INT_MIN;
        }
        
        return this->arr[this->top2];
    }

    int size1(){
        return this->top1+1;
    }

    int size2(){
        return this->size-this->top2;
    }
};

int main() {
    
    stack s(10);
    
    // Demonstrate isFull and isEmpty functions
    cout << "Is stack1 empty? " << (s.isempty1() ? "Yes" : "No") << endl;
    cout << "Is stack2 empty? " << (s.isempty2() ? "Yes" : "No") << endl;

    // Push elements into stack1
    s.push1(1);
    s.push1(2);
    s.push1(3);

    // Push elements into stack2
    s.push2(10);
    s.push2(20);
    s.push2(30);

    // Check if stacks are full
    cout << "Is the stack full? " << (s.isFull() ? "Yes" : "No") << endl;

    // Check top elements of both stacks
    cout << "Top element of stack1: " << s.top1_element() << endl;
    cout << "Top element of stack2: " << s.top2_element() << endl;

    // Pop elements from both stacks
    s.pop1();
    s.pop2();

    // Check top elements again after popping
    cout << "Top element of stack1 after pop: " << s.top1_element() << endl;
    cout << "Top element of stack2 after pop: " << s.top2_element() << endl;

    // Check sizes of both stacks
    cout << "Size of stack1: " << s.size1() << endl;
    cout << "Size of stack2: " << s.size2() << endl;

    // Attempt to push into full stacks
    for (int i = 4; i <= 9; i++) {
        s.push1(i);
        s.push2(i + 10);
    }

    // Demonstrate isFull function
    cout << "Is the stack full after pushing more elements? " << (s.isFull() ? "Yes" : "No") << endl;

    // Try to push to full stacks
    s.push1(10); // Should indicate stack1 is full
    s.push2(20); // Should indicate stack2 is full

    // Check if stacks are empty after all operations
    cout << "Is stack1 empty after operations? " << (s.isempty1() ? "Yes" : "No") << endl;
    cout << "Is stack2 empty after operations? " << (s.isempty2() ? "Yes" : "No") << endl;

    return 0;
}