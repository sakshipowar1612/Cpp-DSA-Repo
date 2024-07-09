#include <iostream>
#include <deque> //<--------------DQUEUE
using namespace std;

// Doubly Ended Queue
class dQueue
{

    int *arr;
    int front;
    int rear;
    int size;

public:
    dQueue(int _size)
    {
        this->size = _size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void pushBack(int _data)
    {
        if (this->front == 0 && this->rear == this->size - 1 || front == rear + 1)
        {
            cout << "OverFlow" << endl;
        }
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = _data;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = _data;
        }
        else
        {
            rear++;
            arr[rear] = _data;
        }
    }

    void pushFront(int _data)
    {
        if (this->front == 0 && this->rear == this->size - 1 || front == rear + 1)
        {
            cout << "OverFlow" << endl;
        }
        else if (front == -1 & rear == -1)
        {
            front++;
            rear++;
            arr[front] = _data;
        }
        else if (rear != size - 1 && front == 0)
        {
            front = size - 1;
            arr[front] = _data;
        }
        else
        {
            front--;
            arr[front] = _data;
        }
    }

    void popFront()
    {
        if (front == -1 && rear == -1)
        {
            cout << "UnderFlow" << endl;
            return;
        }
        else if (front == rear)
        {
            arr[front] = -1;
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            arr[front] = -1;
            front = 0;
        }
        else
        {
            arr[front] = -1;
            front++;
        }
    }

    void popBack()
    {
        if (front == -1 && rear == -1)
        {
            cout << "UnderFlow" << endl;
            return;
        }
        else if (front == rear)
        {
            arr[rear] = -1;
            front = rear = -1;
        }
        else if (rear == 0)
        {
            arr[rear] = -1;
            rear = size-1;
        }
        else
        {
            arr[rear] = -1;
            rear--;
        }
    }
};