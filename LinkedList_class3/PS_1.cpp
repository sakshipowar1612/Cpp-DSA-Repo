#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node() : data(0), next(NULL) {}

    Node(int _data) : data(_data), next(NULL) {}

};

void printLL(Node *head){
    Node *temp = head;
    while(temp){
        cout << temp->data;
        if(temp->next) cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

int printNN(Node *head){
    Node *temp = head;
    int count = 0;
    while(temp){
        count += 1;
        temp = temp->next;
    }
    return count;
}

void insertAtHead(Node*&head,int _data){
    Node *temp = new Node(_data);
    temp ->next = head;
    head = temp;
    return;
}

void insertAtTail(Node* &head, int _data){
    Node *nn = new Node(_data);
    if (head == NULL)
    {
        head = nn;
    }
    else{
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = nn;
    }
    return;
}

void insertAtPosition(Node *&head, int _data, int position){
    int size = printNN(head);
    if (position <= 1)
    {
        insertAtHead(head, _data);
    }
    else if (position >= size + 1)
    {
        insertAtTail(head, _data);
    }
    else{
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

void reverse(Node *&curr, Node *&prev) {
    if (curr == NULL) {
        return;
    } else {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        reverse(curr, prev);
    }
}

void recursivereverse(Node *&head) { // Pass head by reference
    Node *curr = head, *prev = NULL;
    reverse(curr, prev);
    head = prev;
}

int main(){
    Node *head = NULL; // Initialize head as NULL
    insertAtPosition(head, 2, 1);
    insertAtPosition(head, 4, 2);
    insertAtPosition(head, 6, 3);
    insertAtPosition(head, 8, 4);
    insertAtPosition(head, 10, 5);
    printLL(head);
    recursivereverse(head);
    printLL(head);
}
