#include<iostream>
#include<queue>
#include<stack>
using namespace std;

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



void interLeaveQueue(queue<int>&q){
    int size=q.size();
    int n=0;
    if (size%2==0)
    {
        n = size/2;
    }
    else{
        n = size/2+1;
    }
    queue<int>q1;
    while (n)
    {
        q1.push(q.front());
        q.pop();
        n--;
    }
    int data=q1.front();
    while (q.front()!=data || !q1.empty())
    {
        if (!q1.empty())
        {
            q.push(q1.front());
            q1.pop();
        }

        q.push(q.front());
        q.pop(); 
    }
 
}




int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    // q.push(60);
    printQ(q);
    interLeaveQueue(q);
    printQ(q);
 
}