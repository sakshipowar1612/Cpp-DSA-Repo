#include<iostream>
#include<stack>
using namespace std;


void insertAtBottom(stack<int>&sta, int ele){
    if (sta.empty())
    {
        sta.push(ele);
        return;
    }
    
    int data = sta.top();
    sta.pop();
    insertAtBottom(sta, ele);
    sta.push(data);
}

void printStack(stack<int>st){
    if (st.empty())
    {
        return;
    }
    int data = st.top();
    cout << data << " ";
    st.pop();
    printStack(st);
    st.push(data);
    
}

int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);    
    st.push(40);
    st.push(50);
    st.push(60);

    printStack(st);
    cout << endl;
    insertAtBottom(st, 0);
    printStack(st);
    cout << endl;


}