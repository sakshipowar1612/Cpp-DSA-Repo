//Add 1 to LL
#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(){
        this->next = NULL;
    }

    Node(int _data){
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

void reverseLL(Node *&head){
    Node *curr = head, *prev = NULL, *temp;
    while (curr)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
    return;
}

void addOne(Node* &head){
    reverseLL(head);
    Node* temp = head, *prev;
    int carry = 1;
    while (temp)
    {
        temp->data += carry;
        int digit = temp->data%10;
        carry =  temp->data/10;
        temp->data = digit;
        if (carry == 0)
        {
            break;
        }
        prev = temp;
        temp = temp->next;
        
    }
    if (carry)
    {
        prev->next = new Node(1);
    }
    
    
    reverseLL(head);
    
}

int main(){
    Node *head = NULL;
    insertAtPosition(head, 9, 1);
    insertAtPosition(head, 9, 2);
    insertAtPosition(head, 9, 3);
    printLL(head);

    addOne(head);
    printLL(head);
}