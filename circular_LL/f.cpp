#include<iostream>
#include<limits.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

int size_CLL(Node* root){
    int count = 0;
    if (root==NULL)
    {
        return count;
    }
    Node* curr = root;
    do
    {
        count++;
        curr = curr->next;
    } while (curr!=root);
    return count;
}

void insertAtHead(Node* &root, int data){
    Node* nn = new Node(data);
    if (root==NULL)
    {
        root = nn;
        root->next = root;
        return;
    }
    Node* curr = root;
    while(curr->next!=root){
        curr = curr->next;
    }
    nn->next = curr->next;
    curr->next = nn;
    root = nn;
    return;
}

void insertAtTail(Node* &root, int data){
    Node* nn = new Node(data);
    if (root==NULL)
    {
        root = nn;
        root->next = root;
        return;
    }
    Node* curr = root;
    while(curr->next!=root){
        curr = curr->next;
    }
    nn->next = curr->next;
    curr->next = nn;
    return;
}

void traverseCLL(Node* &root){
    if (root == NULL) {
        return;
    }
    Node* curr = root;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != root);
    cout << endl;
}

void insertAtPosition(Node* &root, int data, int position){
    Node* nn = new Node(data);
    int size = size_CLL(root);
    if (root==NULL)
    {
        root = nn;
        root->next = root;
        return;
    }
    else if (position<=1)
    {
        insertAtHead(root, data);
    }
    else if (position >= size)
    {
        insertAtTail(root, data);
    }
    else{
        Node* curr = root, *prev=NULL;
        while(position!=1){
            prev = curr;
            curr = curr->next;
            position--;
        }
        prev->next = nn;
        nn->next = curr;
    }
    return;
}

int deleteAtHead(Node* &root){
    if (root==NULL)
    {
        delete root;
        return INT_MIN;
    }
    Node* last = root;
    while(last->next!=root){
        last = last->next;
    }
    last->next = root->next;
    int ans = root->data;
    Node* node = root;
    root = root->next;
    node->next = NULL;
    delete node;
    return ans;
}

int deleteAtTail(Node* &root){
    if (root==NULL)
    {
        delete root;
        return INT_MIN;
    }
    Node* last = root, *prev=NULL;
    while(last->next!=root){
        prev = last;
        last = last->next;
    }
    prev->next = root;
    int ans = last->data;
    last->next=NULL;
    delete last;
    return ans;
}

int deleteAtPosition(Node* &root, int position){
    int size = size_CLL(root);
    if (root==NULL)
    {
        delete root;
        return INT_MIN;
    }
    else if (position<=1)
    {
        return deleteAtHead(root);
    }
    else if (position>=size)
    {
        return deleteAtTail(root);
    }
    else{
        Node* curr = root, *prev = NULL;
        while (position!=1)
        {
            prev = curr;
            curr = curr->next;
            position--;
        }
        prev->next = curr->next;
        curr->next = NULL;
        int ans = curr->data;
        delete curr;
        return ans;
    }
    
    
}

void create_CLL(Node* &root){
    int data;
    while (true) {
        cout << "Enter data: ";
        cin >> data;
        if (data == -1) {
            break;
        }
        insertAtTail(root, data);
    }
}

int main(){
    Node* A=NULL;
    create_CLL(A);
    traverseCLL(A);
    insertAtPosition(A, 1, 3);
    traverseCLL(A);
    deleteAtPosition(A,1);
    traverseCLL(A);
    deleteAtPosition(A, size_CLL(A)+1);
    traverseCLL(A);
    deleteAtPosition(A, 3);
    traverseCLL(A);
    return 0;
}