#include<iostream>
#include<queue>
#include<stack>
using namespace std;

//U can also solve using stack;
void reverseQueue(queue<int>&q){
    if (q.empty())
    {
        return;
    }
    int data = q.front();
    q.pop();
    reverseQueue(q);
    q.push(data);  
}


// <------------------My Approach--------------------->
void reverseKEle(queue<int>&q, int k){
    queue<int>ans;
    int size = q.size();
    for (int i = 0; i < k; i++)
    {
        ans.push(q.front());
        q.pop();
        
    }
    reverseQueue(ans);
    for (int i = k; i < size; i++)
    {
        ans.push(q.front());
        q.pop();
    } 
    q = ans;
}


void reverseKEleOfQ(queue<int>&q, int k){
    stack<int>s;
    int n = q.size()-k;
    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    while (n)
    {
        q.push(q.front());
        q.pop();
        n--;
    }   
}

void printQ(queue<int>q){
    if (q.empty())
    {
        return;
    }
    cout << q.front() << " ";
    q.pop();
    printQ(q);
    cout << endl;
    return;   
}

int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    printQ(q);
    // reverseQueue(q);
    // reverseKEle(q, 3);
    reverseKEleOfQ(q,3);
    printQ(q);






}