#include<iostream>
#include<queue>
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
    reverseKEle(q, 3);
    printQ(q);






}