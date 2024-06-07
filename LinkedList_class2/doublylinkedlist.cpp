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

int main(){
    Node *head = new Node(10);
    print(head);
}