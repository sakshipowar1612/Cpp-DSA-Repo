#include<iostream>
using namespace std;

class cQueue{
    public:

    int  *arr;
    int front; 
    int rear;
    int size;

    cQueue(int _size){
        arr = new int[_size];
        this->size = _size;
        this->front = -1;
        this->rear = -1;
    }

    void push(int _data){
        if (this->front == 0 && this->rear == this->size-1 || front==rear+1)
        {
            cout << "OverFlow" << endl;
        }
        else if(front == -1 && rear == -1 ){
            front++;
            rear++;
            arr[rear] = _data;
        }
        else if (rear == size-1 && front != 0)
        {
            rear = 0;
            arr[rear] = _data;
        }
        else{
            rear++;
            arr[rear] = _data;
        }   
        
    }

    void pop(){
        if (front==-1 && rear==-1)
        {
            cout << "UnderFlow" << endl;
            return;
        }
        else if (front==rear)
        {
           arr[front] = -1;
            front = rear = -1;
        }
        else if (front==size-1)
        {
            arr[front]=-1;
            front=0;
        }
        else{
            arr[front]=-1;
            front++;
        }
        
        
    }

    void print()
    {
        cout << "Printing Queue: " << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main(){
    cQueue q(5);
    // q.print();
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.print();
    q.push(60);
    q.print();
    q.pop();
    q.print();
    q.pop();
    q.print();
    q.push(60);
    q.print();
    q.push(70);
    q.print();
    q.push(80);
    q.print();
    q.pop();
    q.print();
    q.push(80);
    q.print();


}