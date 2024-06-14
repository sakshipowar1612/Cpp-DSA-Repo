#include<iostream>
#include<stack>
using namespace std;

int main() {
    // Creation of a stack
    stack<int> st;

    // Insertion of elements into the stack
    st.push(10);
    st.push(20);
    st.push(30);

    // Output the size of the stack
    cout << "Size of stack: " << st.size() << endl;

    // Check if the stack is empty
    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl;

    // Output the top element of the stack
    cout << "Top element of stack: " << st.top() << endl;

    // Remove the top element from the stack
    st.pop();
    cout << "Size of stack after one pop: " << st.size() << endl;

    
    cout << "Top element of stack: " << st.top() << endl;

    st.pop();
    cout << "Size of stack after second pop: " << st.size() << endl;

    cout << "Top element of stack: " << st.top() << endl;

    st.pop();
    cout << "Size of stack after third pop: " << st.size() << endl;

    cout << "Top element of stack: " << st.top() << endl;

    // Check if the stack is empty again
    cout << "Is stack empty now? " << (st.empty() ? "Yes" : "No") << endl;

    return 0;
}

/*
Expected Output:
Size of stack: 3
Is stack empty? No
Top element of stack: 30
Size of stack after one pop: 2
Size of stack after second pop: 1
Size of stack after third pop: 0
Is stack empty now? Yes
*/
