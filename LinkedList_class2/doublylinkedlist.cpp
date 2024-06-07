#include<iostream>
using namespace std;

class Node{
    public:
    Node *prev;
    int data;
    Node *next;

    Node(){
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int _data){
        this->prev = NULL;
        this->data = _data;
        this->next = NULL; 
    }
};

void print(Node *head){
    Node*temp = head;
    while(temp){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

int findLen(Node* head){
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
    
}

void insertAtHead(Node *&head, int _data){
    Node *nn = new Node(_data);
    if (head == NULL)
    {
        head = nn;
    }
    else{
        nn->next = head;
        head->prev = nn;
        head = nn;
    }
    return;
}

void insertAtTail(Node*&head, int _data){
    Node *nn = new Node(_data);
    if (head == NULL)
    {
        head = nn;
    }
    else{
        Node *temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = nn;
        nn->prev = temp;
    }
    return;
}

void insertAtAnyposition(Node*&head, int _data, int position){
    Node *nn = new Node(_data);
    int size = findLen(head);
    if (position <= 1)
    {
        insertAtHead(head, _data);
    }
    else if (position > size)
    {
        insertAtTail(head, _data);
    }
    else{
        Node *curr = head;
        while (position!=1)
        {
           curr = curr->next;
           position--;
        }
        (curr->prev)->next = nn;
        nn->prev = curr->prev;
        nn->next = curr;
        curr->prev = nn;
    }
    return;
    
}


int main(){
    Node *head = new Node(10);
    print(head);
    insertAtHead(head, 5);
    print(head);
    insertAtHead(head, 0);
    print(head);
    
    insertAtTail(head, 15);
    print(head);
    insertAtTail(head, 20);
    print(head);

    insertAtAnyposition(head, -5, 1);
    print(head);
    insertAtAnyposition(head, 25, 8);
    print(head);
    insertAtAnyposition(head, 7, 4);
    print(head);
    insertAtAnyposition(head, -5, 8);
    print(head);
    
    
    
}