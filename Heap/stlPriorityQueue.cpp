#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int>pq;
    pq.push(23);
    pq.push(21);
    pq.push(12);
    pq.push(56);
    pq.push(78);

    cout << "Size : " << pq.size() << endl;
    
    cout << "top : "  << pq.top() << endl;

    pq.pop();

    cout << "Size : " << pq.size() << endl;

    cout <<  "top : " << pq.top() << endl << endl;

    // min priority queue

    priority_queue<int, vector<int>, greater<int> >minpq;


    minpq.push(23);
    minpq.push(21);
    minpq.push(12);
    minpq.push(56);
    minpq.push(78);

    cout << "Size : " << minpq.size() << endl;
    
    cout << "top : "  << minpq.top() << endl;

    minpq.pop();

    cout << "Size : " << minpq.size() << endl;

    cout <<  "top : " << minpq.top() << endl;






}