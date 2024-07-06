#include <iostream>
#include <stack>
#include<limits>
using namespace std;

int mid(stack<int>st, int pos){
    if (pos==1)
    {
        return st.top();
    }
    char ch = st.top();
    st.pop();
    pos--;
    int ans = mid(st, pos);
    st.push(ch);
    return ans;
}


int giveMiddlaEle(stack<int>st){
    int size = st.size();
    int position;
    if (size%2==0)
    {
        position = size/2;
    }
    else{
        position = size/2+1;
    }
   return mid(st, position);
}

int main(){
    stack<int>st;
    st.push(10);
    st.push(33);
    // st.push(47);
    // st.push(25);
    // st.push(37);
   

    cout << giveMiddlaEle(st) << endl;
}