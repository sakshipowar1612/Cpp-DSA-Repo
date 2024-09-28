#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;


    Node(){
        // cout << "I am inside Default Constructor" << endl;
        this->next = NULL;
    }
    Node(int _data){
        // cout << "I am inside Parameterized Constructor" << endl;
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


    // Node *hey = NULL;
    // insertAtTail(hey, 456);
    // printLL(hey);
}