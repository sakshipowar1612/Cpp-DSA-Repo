#include<iostream>
#include <map>
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

void printLL(Node* head){
    Node* temp=head;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

int printNN(Node *head){
    Node* temp=head;
    int count = 0;
    while (temp)
    {
        count ++;
        temp = temp->next;
    }
    return count;
}

void removeDuplicates(Node*head){ //<<----------------------No need of sorted LL
    map<int, bool>table;
    Node* temp = head;
    Node*prev = NULL;
    while (temp)
    {
        Node* d = NULL;
        if (table[temp->data]!=true)
        {
            table[temp->data]=true;
            prev = temp;
            temp = temp->next;
        }
        else if (table[temp->data]==true)
        {
           prev->next = temp->next;
           d = temp;
           temp = temp->next;
        }
        
        if (d)
        {
            d->next = NULL;
            delete d;
        }
    }
}

void removedup(Node* head){ //<--------------------for sorted LL only.
    Node* temp = head;
    while (temp)
    {
        Node* del = NULL;
        if (temp->next && temp->data == temp->next->data)
        {
            del = temp->next;
            temp->next = temp->next->next;
        }
        else{
            temp = temp->next;
        }
        if (del)
        {
            del->next = NULL;
            delete del;
        }
        
        
    }
    return;
}

int main(){
    Node *head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(2);

    printLL(head);
    removeDuplicates(head);
    printLL(head);

}

