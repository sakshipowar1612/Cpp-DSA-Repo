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

Node* reverseKnodes(Node* &head, int k){
    if (!head || !head->next || printNN(head)<k)
    {
        return head;
    }

    Node* curr = head, *prev = NULL;
    int position = k;
    while (position)
    {
        Node*nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        position--; 
    }
    Node* prevhead = head;
    head = prev;
    prevhead->next = reverseKnodes(curr, k); 
    return head;
    
}

int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    // head->next->next->next->next->next = new Node(6);

    printLL(head);
    Node* reverse = reverseKnodes(head, 3);
    printLL(reverse);
    
}
 