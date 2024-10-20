#include<iostream>
#include<limits.h>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    
    Node(){
        this->prev=NULL;
        this->next=NULL;
    }
    Node(int _data){
        this->data=_data;
        this->next=NULL;
        this->prev=NULL;
    }
};

int sizeDLL(Node* root){
    int count = 0;
    if (root==NULL)
    {
        return count;
    }
    Node* curr = root;
    while (curr)
    {
        count++;
        curr = curr->next;
    }
    return count;
}

void traversel(Node* root){
    if(root==NULL){
        return;
    }
    Node* curr= root;
    while(curr){
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void reverseTraversal(Node* root){
    if(root==NULL){
        return;
    }
    Node* curr = root;
    while(curr->next){
        curr = curr->next;
    }
    while(curr){
        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << endl;
}

void insertAtHead(Node* &head, int key){
    Node* nn = new Node(key);
    if(head==NULL){
        head = nn;
        delete nn;
        return;
    }
    nn->next = head;
    head->prev = nn;
    head == nn;
    return;
}

void insertAtTail(Node* &head, int key){
    Node* nn = new Node(key);
    if(head==NULL){
        head = nn;
        nn = NULL;
        delete nn;
        return;
    }
    Node* curr = head;
    while(curr->next){
        curr = curr->next;
    }
    curr->next = nn;
    nn->prev = curr;
    nn->next = NULL;
    nn = NULL;
    delete nn;
    return;

}

int deleteAtHead(Node* &head){
    if(head==NULL){
        return INT_MIN;
    }
    Node* node = head;
    head = head->next;
    head->prev = NULL;
    node->next=NULL;
    int ans = node->data;
    delete node;
    return ans;
}


int deleteAtTail(Node* &head){
    if(head==NULL){
        return INT_MIN;
    }

    Node* curr = head;
    while (curr->next)
    {
        curr=curr->next;
    }
    Node* prev = curr->prev;
    prev->next = NULL;
    int ans = curr->data;
    curr->prev=NULL;
    delete curr;
    return ans;
}

void createDLL(Node* &root){
    int data;
    cout << "Enter data: ";
    cin >> data;
    if(data==-1){
        return;
    }
    insertAtTail(root, data);
    createDLL(root);
}

void insertAtPosition(Node* &root, int data, int position){
    Node* nn= new Node(data);
    int size = sizeDLL(root);
    if(root==NULL){
        root = nn;
        return;
    }
    else if(position<=1){
        insertAtHead(root, data);
        return;
    }
    else if(position>=size){
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
        nn->prev = prev;
        nn->next = curr;
        curr->prev = nn;
        prev = NULL;
        nn = NULL;
        curr = NULL;
        delete prev, nn, curr;
        return;

    }
}

int deleteAtPosition(Node* &root, int position){
    int size = sizeDLL(root);
    if (root==NULL)
    {
        delete root;
        return INT_MIN;
    }
    else if (position<=1)
    {
        deleteAtHead(root);
    }
    else if (position >= size)
    {
        deleteAtTail(root);
    }
    else{
        Node* curr = root, *prev = NULL;
        while(position!=1){
            prev = curr;
            curr = curr->next;
            position--;
        }
        prev->next = curr->next;
        (curr->next)->prev = prev;
        curr->next = NULL;
        curr->prev = NULL;
        int ans = curr->data;
        delete curr;
        return ans;
    }
    
    
}


int main(){
    Node* A=NULL;
    createDLL(A);
    traversel(A);
    reverseTraversal(A);
    // deleteAtHead(A);
    // traversel(A);
    // reverseTraversal(A);
    // deleteAtTail(A);
    // traversel(A);
    // reverseTraversal(A);
    cout << sizeDLL(A) << endl;
    insertAtPosition(A, 90, 4);
    cout << sizeDLL(A) << endl;
    traversel(A);
    reverseTraversal(A);
    deleteAtPosition(A, 4);
    cout << sizeDLL(A) << endl;
    traversel(A);
    reverseTraversal(A);
    deleteAtPosition(A, 1);
    cout << sizeDLL(A) << endl;
    traversel(A);
    reverseTraversal(A);
    deleteAtPosition(A, sizeDLL(A));
    cout << sizeDLL(A) << endl;
    traversel(A);
    reverseTraversal(A);
    


}