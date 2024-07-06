#include <iostream>
#include <stack>
using namespace std;

//my solution
void remove(stack<int>&sta, int data){
    if (sta.empty())
    {
        sta.push(data);
        return;
    }
    int temp = sta.top();
    if (temp < data)
    {
        sta.pop();
        remove(sta, data);
        sta.push(temp);
    }
    else{
        sta.push(data);
        
    }
    return;
}

void sortTheStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int data = s.top();
    s.pop();
    sortTheStack(s);
    if (s.empty())
    {
        s.push(data);
    }
    else
    {
        if (data > s.top())
        {
            remove(s, data);
            
        }
        else{
            s.push(data);
        }
    }
}

//love babbar solution

void insertInSortedStack(stack<int>&s, int data){
    if (s.empty() || s.top() <= data )
    {
        s.push(data);
        return;
    }
    int temp = s.top();
    s.pop();
    insertInSortedStack(s, data);
    s.push(temp);
}

void sortStack(stack<int>&s){
    if (s.empty())
    {
        return;
    }
    int temp = s.top();
    s.pop();
    sortStack(s);
    insertInSortedStack(s, temp);
}


void printStack(stack<int> st)
{
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

int main()
{
    stack<int> st;
    st.push(3);
    st.push(1);
    st.push(0);
    st.push(8);
    st.push(5);
    st.push(0);
    // sortTheStack(st);
    sortStack(st);
    printStack(st);
}