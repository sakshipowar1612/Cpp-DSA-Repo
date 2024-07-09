#include <iostream>
#include <limits>
using namespace std;

class CustomQueue
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    CustomQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void push(int val)
    {
        if (rear == size - 1)
        {
            cout << "Queue OverFlow" << endl;
            return;
        }
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        else
        {
            rear++;
            arr[rear] = val;
        }
    }

    void pop()
    {
        if (rear == -1 && front == -1)
        {
            cout << "Queue underFlow" << endl;
            return;
        }
        else if (front == rear)
        {
            // single element
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else
        {
            arr[front] = -1;
            front++;
        }
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return 1;
        else
            return 0;
    }
    int getSize()
    {
        // important
        if (front == -1 && rear == -1)
            return 0;
        else
            return (rear - front + 1);
    }
    int getFront()
    {
        if (front == -1)
        {
            cout << "Noe lement in the Queue" << endl;
            return -1;
        }
        else
            return arr[front];
    }
    int getRear()
    {
        if (rear == -1)
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return arr[rear];
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
    ~CustomQueue()
    {
        cout << "Destructor Called" << endl;
        delete[] arr;
    }
};

int main()
{
    CustomQueue q(5);

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    q.print();

    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;
    cout << "Queue size: " << q.getSize() << endl;

    q.pop();
    q.print();

    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;
    cout << "Queue size: " << q.getSize() << endl;

    q.pop();
    q.pop();
    q.print();

    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;
    cout << "Queue size: " << q.getSize() << endl;

    q.push(60);
    q.push(70);
    q.print();

    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;
    cout << "Queue size: " << q.getSize() << endl;

    while (!q.isEmpty())
    {
        q.pop();
        q.print();
    }
    cout << "Queue size: " << q.getSize() << endl;

    return 0;
}
