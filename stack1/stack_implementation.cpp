#include<iostream>
using namespace std;

class Stack {
public:
    int *arr;
    int top;
    int size;

    // Constructor to initialize stack
    Stack(int size) {
        arr = new int[size];
        this->top = -1;
        this->size = size;
    }

    // Method to push an element onto the stack
    void push(int data) {
        if (this->isFull()) {
            cout << "<---------Overflow---------->" << endl;
            return;
        }
        top++;
        arr[top] = data;
    }

    // Method to pop an element from the stack
    void pop() {
        if (this->isEmpty()) {
            return;
        }
        top--;
    }

    // Method to check if the stack is empty
    bool isEmpty() {
        return this->top == -1;
    }

    // Method to check if the stack is full
    bool isFull() {
        return this->top == this->size - 1;
    }

    // Method to get the top element of the stack
    int getTop() {
        if (this->isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return this->arr[top];
    }

    // Method to get the current size of the stack
    int getSize() {
        return this->top + 1;
    }

    // Method to print the stack details
    void print() {
        cout << "Top Index: " << this->top << endl;
        cout << "Top Element: " << this->getTop() << endl;
        cout << "Stack: ";
        for (int i = 0; i <= this->top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl << endl;
    }
};

int main() {
    // Create a stack of size 10
    Stack st(10);
    
    // Check if the stack is empty
    cout << "Is stack empty? " << (st.isEmpty() ? "Yes" : "No") << endl;

    // Push elements onto the stack
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
   


    // Display stack details
    cout << "Stack size: " << st.getSize() << endl;
    cout << "Is stack empty? " << (st.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full? " << (st.isFull() ? "Yes" : "No") << endl;
    cout << "Top element: " << st.getTop() << endl;
    st.print();

    // Pop elements from the stack and display details
    st.pop();
    cout << "Stack size after pop: " << st.getSize() << endl;
    cout << "Is stack empty? " << (st.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full? " << (st.isFull() ? "Yes" : "No") << endl;
    cout << "Top element after pop: " << st.getTop() << endl;
    st.print();

    st.pop();
    cout << "Stack size after second pop: " << st.getSize() << endl;
    cout << "Is stack empty? " << (st.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full? " << (st.isFull() ? "Yes" : "No") << endl;
    cout << "Top element after second pop: " << st.getTop() << endl;
    st.print();

    st.pop();
    cout << "Stack size after third pop: " << st.getSize() << endl;
    cout << "Is stack empty? " << (st.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full? " << (st.isFull() ? "Yes" : "No") << endl;
    cout << "Top element after third pop: " << st.getTop() << endl;
    st.print();

    st.pop();
    cout << "Stack size after fourth pop: " << st.getSize() << endl;
    cout << "Is stack empty? " << (st.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full? " << (st.isFull() ? "Yes" : "No") << endl;
    cout << "Top element after fourth pop: " << st.getTop() << endl;
    st.print();

    st.pop();
    cout << "Stack size after fifth pop: " << st.getSize() << endl;
    cout << "Is stack empty? " << (st.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full? " << (st.isFull() ? "Yes" : "No") << endl;
    cout << "Top element after fifth pop: " << st.getTop() << endl;
    st.print();

    return 0;
}

/*
Expected Output:
Is stack empty? Yes
Stack size: 5
Is stack empty? No
Is stack full? No
Top element: 5
Top Index: 4
Top Element: 5
Stack: 1 2 3 4 5 

Stack size after pop: 4
Is stack empty? No
Is stack full? No
Top element after pop: 4
Top Index: 3
Top Element: 4
Stack: 1 2 3 4 

Stack size after second pop: 3
Is stack empty? No
Is stack full? No
Top element after second pop: 3
Top Index: 2
Top Element: 3
Stack: 1 2 3 

Stack size after third pop: 2
Is stack empty? No
Is stack full? No
Top element after third pop: 2
Top Index: 1
Top Element: 2
Stack: 1 2 

Stack size after fourth pop: 1
Is stack empty? No
Is stack full? No
Top element after fourth pop: 1
Top Index: 0
Top Element: 1
Stack: 1 

Stack size after fifth pop: 0
Is stack empty? Yes
Is stack full? No
Top element after fifth pop: Stack is empty
-1
Top Index: -1
Top Element: Stack is empty
-1
Stack: 
*/
