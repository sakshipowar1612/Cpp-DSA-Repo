//Delete N Nodes from LL after N Nodes
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


void linkdelete(Node* head, int M, int N){
    Node* curr = head;
    Node* temp = NULL;
    while(curr){
        for (int i = 1; i < M && curr!=NULL ; i++)
        {
            curr = curr->next;
        }
        if (!curr)
        {
            return;
        }
        temp = curr->next;
        for (int j = 1; j <= N && temp!=NULL; j++)
        {
            temp = temp->next;
        }
        curr->next = temp;
        curr = temp;
        
    }
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    printLL(head);
    linkdelete(head, 3, 2);
    printLL(head);

}