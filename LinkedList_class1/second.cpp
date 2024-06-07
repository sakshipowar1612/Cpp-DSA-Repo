#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(){
        this->next = NULL;
    }

    Node(int _data){
        this->data = _data;
        this->next = NULL;
    }

};

void printLL(Node *head){
    Node *temp = head;
    while(temp){
        cout << temp->data << "->";
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


void insertAtHead(Node*&head,int _data){  //pass by reference karna hai
    //craete a new node
    if(head == NULL){
        head = new Node(_data);
        return;
    }
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
    // if (position<1)
    // {
    //     cout << "Not possible" << endl;
    // }
    if (position <= 1)
    {
        insertAtHead(head, _data);
       
    }
    else if (position >= size+1)
    {
        insertAtTail(head, _data);
       
    }
    else{
        Node *nn = new Node(_data);
        Node *curr = head;
        Node*prev;
        
        while (position!=1)
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

int main(){
    Node *head = NULL;
    insertAtHead(head, 2);
    insertAtTail(head, 4);
    insertAtTail(head, 6);
    insertAtTail(head, 8);
    insertAtPosition(head, 0, 1);
    printLL(head);
    insertAtPosition(head, 10, 6);
    printLL(head);
    insertAtPosition(head, 7, 5);
    printLL(head);
    insertAtPosition(head, -2, -1);
    printLL(head);
}