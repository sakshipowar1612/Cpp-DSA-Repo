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

int printNN(Node *head){
    Node *temp = head;
    int count = 0;
    while(temp){
        count += 1;
        temp = temp->next;
    }
    return count;
}


void deleteNode(Node *&head, int _data){
    if (head == NULL)
    {
        cout << "LinkedList is empty" << endl;
    }
    else if (head->data == _data)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    else 
    {
        Node *curr=head,*prev;
        while (curr->data != _data)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
    }
    return;
}

void deleteByPosition(Node*&head, int position){
    int size = printNN(head);
    if (!head)
    {
        cout << "LinkedList is empty" << endl;
    }
    else if (position<=1)
    {
        Node *temp=head;
        head = temp->next;
        delete temp;
    }
    else 
    {
        Node *curr = head, *prev;
        while (position!=1)
        {
            prev = curr;
            curr = curr->next;
            position--;
        }
        prev->next = curr->next;
        delete curr;
    }
    return;
}

void printLL(Node *head){
    Node *temp = head;
    while(temp){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
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

// void sa(Node* &head){
//     cout << &head << endl;
// }

void ca( int a){
    cout << &a;
}


int main(){

    //creation of node
    // Node a; //<---------------STATIC ALLLOCATION

    // Node *head = new Node(); //<-----------------DYNAMIC ALLOCATION


    Node *first = new Node(1);  //new Node()  <-------gives the address
    Node *sec = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);

    first->next = sec;
    sec->next = third;
    third->next = fourth;
    fourth->next = fifth;
    //linked list has created
    printLL(first);
    cout << "No. of nodes = " << printNN(first) << endl;
    cout << "inserting node at begining" << endl;
    insertAtHead(first, 0);
    printLL(first);
    cout << "inserting node at end" << endl;
    insertAtTail(first, 6);
    printLL(first);
    deleteNode(first, 4);
    printLL(first);
    deleteByPosition(first, 1);
    printLL(first);
    deleteByPosition(first, 5);
    printLL(first);
    deleteByPosition(first, 2);
    printLL(first);

    // cout << &first << endl;
    // sa(first);
    int a = 2;
    cout << &a << endl;
    ca(a);

}