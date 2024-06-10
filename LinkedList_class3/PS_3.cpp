#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->next = NULL;
    }
    Node(int _data)
    {
        this->data = _data;
        this->next = NULL;
    }
};

void printLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data;
        if (temp->next)
            cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

int printNN(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp)
    {
        count += 1;
        temp = temp->next;
    }
    return count;
}

void insertAtHead(Node *&head, int _data)
{
    Node *temp = new Node(_data);
    temp->next = head;
    head = temp;
    return;
}

void insertAtTail(Node *&head, int _data)
{
    Node *nn = new Node(_data);
    if (head == NULL)
    {
        head = nn;
    }
    else
    {
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = nn;
    }
    return;
}

void insertAtPosition(Node *&head, int _data, int position)
{
    int size = printNN(head);
    if (position <= 1)
    {
        insertAtHead(head, _data);
    }
    else if (position >= size + 1)
    {
        insertAtTail(head, _data);
    }
    else
    {
        Node *nn = new Node(_data);
        Node *curr = head;
        Node *prev = NULL;

        while (position != 1)
        {
            prev = curr;
            curr = curr->next;
            position--;
        }
        prev->next = nn;
        nn->next = curr;
    }
    return;
}


Node *returnMiddle(Node *head){
    Node *slow =head, *fast=head;
    while(fast->next){ //fast <=========================== IMP
        fast = fast->next;
        if(fast->next) //fast <========================== IMP
        {
            fast = fast->next;
            //here fast has taken two steps
            //now slow can also take one step
            slow = slow->next;
        }

    } 
    return slow;
}

int main()
{
    Node *head = NULL; // Initialize head as NULL
    insertAtPosition(head, 2, 1);
    insertAtPosition(head, 4, 2);
    insertAtPosition(head, 6, 3);
    insertAtPosition(head, 8, 4);
    insertAtPosition(head, 10, 5);
    insertAtPosition(head, 12, 6);
    printLL(head);
    Node *middle = returnMiddle(head);
    printLL(middle);
    
}