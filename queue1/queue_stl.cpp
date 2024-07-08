#include<iostream>
#include<queue>
using namespace std;


int main(){
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout << "Size of Queue is " << q.size() << endl;
    cout << "front element of queue is " << q.front() << endl;
    cout << "last/back/rear element of queue is " << q.back() << endl;
    q.pop();
    cout << "Size of Queue is " << q.size() << endl;
    cout << "front element of queue is " << q.front() << endl;
    cout << "last/back/rear element of queue is " << q.back() << endl;
    q.emplace(11); //push
    cout << "Size of Queue is " << q.size() << endl;
    cout << "front element of queue is " << q.front() << endl;
    cout << "last/back/rear element of queue is " << q.back() << endl;
    
}