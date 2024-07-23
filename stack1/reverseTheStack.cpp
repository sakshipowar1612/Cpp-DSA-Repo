#include<iostream>
#include<stack>
using namespace std;
//TO : n*(n+1)/2 = n^2
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

void reverseStack(stack<int>&sta){
    if (sta.empty())
    {
        return;
    }
    int data = sta.top();
    sta.pop();
    reverseStack(sta);
    insertAtBottom(sta, data);
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
    reverseStack(st);
    printStack(st);
}