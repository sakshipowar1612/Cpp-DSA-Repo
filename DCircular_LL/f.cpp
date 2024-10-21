#include<iostream>
#include<limits.h>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int _data){
        this->data = _data;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Function to get the size of the circular doubly linked list
int sizeDLL(Node* root){
    int count = 0;
    if (root == NULL) {
        return count;
    }
    Node* curr = root;
    do {
        count++;
        curr = curr->next;
    } while (curr != root);  // Fix: loop until we come back to the root
    return count;
}

// Function to traverse the list in forward direction
void traversel(Node* root){
    if (root == NULL) {
        return;
    }
    Node* curr = root;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != root);  // Fix: loop until we come back to the root
    cout << endl;
}

// Function to traverse the list in reverse direction
void reverseTraversal(Node* root){
    if (root == NULL) {
        return;
    }
    Node* curr = root->prev;  // Start from the last node (root's previous)
    do {
        cout << curr->data << " ";
        curr = curr->prev;
    } while (curr != root->prev);  // Fix: loop until we come back to the last node
    cout << endl;
}

// Function to insert a new node at the head of the list
void insertAtHead(Node* &head, int key){
    Node* nn = new Node(key);
    if (head == NULL) {
        head = nn;
        head->next = head;
        head->prev = head;
        return;
    }
    Node* last = head->prev;
    nn->next = head;
    nn->prev = last;
    last->next = nn;
    head->prev = nn;
    head = nn;
}

// Function to insert a new node at the tail of the list
void insertAtTail(Node* &head, int key){
    Node* nn = new Node(key);
    if (head == NULL) {
        head = nn;
        head->next = head;
        head->prev = head;
        return;
    }
    Node* last = head->prev;
    nn->next = head;
    nn->prev = last;
    last->next = nn;
    head->prev = nn;
}

// Function to delete the head node of the list
int deleteAtHead(Node* &head){
    if (head == NULL) {
        return INT_MIN;
    }
    Node* last = head->prev;
    Node* del = head;
    int ans = del->data;
    if (head->next == head) {  // Single node case
        delete head;
        head = NULL;
    } else {
        head = head->next;
        last->next = head;
        head->prev = last;
        delete del;
    }
    return ans;
}

// Function to delete the tail node of the list
int deleteAtTail(Node* &head){
    if (head == NULL) {
        return INT_MIN;
    }
    Node* last = head->prev;
    int ans = last->data;
    if (head->next == head) {  // Single node case
        delete head;
        head = NULL;
    } else {
        Node* secondLast = last->prev;
        secondLast->next = head;
        head->prev = secondLast;
        delete last;
    }
    return ans;
}

// Function to create the doubly linked list by inserting nodes
void createDLL(Node* &root){
    int data;
    cout << "Enter data (-1 to stop): ";
    cin >> data;
    if(data == -1) {
        return;
    }
    insertAtTail(root, data);
    createDLL(root);
}

// Function to insert a node at a specific position
void insertAtPosition(Node* &root, int data, int position){
    Node* nn = new Node(data);
    int size = sizeDLL(root);
    if (root == NULL) {
        root = nn;
        root->next = root;
        root->prev = root;
        return;
    } else if (position <= 1) {
        insertAtHead(root, data);
    } else if (position >= size) {
        insertAtTail(root, data);
    } else {
        Node* curr = root;
        while (position > 1) {
            curr = curr->next;
            position--;
        }
        Node* prevNode = curr->prev;
        nn->next = curr;
        nn->prev = prevNode;
        prevNode->next = nn;
        curr->prev = nn;
    }
}

// Function to delete a node at a specific position
int deleteAtPosition(Node* &root, int position){
    int size = sizeDLL(root);
    if (root == NULL) {
        return INT_MIN;
    } else if (position <= 1) {
        return deleteAtHead(root);
    } else if (position >= size) {
        return deleteAtTail(root);
    } else {
        Node* curr = root;
        while (position > 1) {
            curr = curr->next;
            position--;
        }
        Node* prevNode = curr->prev;
        Node* nextNode = curr->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        int ans = curr->data;
        delete curr;
        return ans;
    }
}

int main(){
    Node* A = NULL;
    createDLL(A);
    traversel(A);
    reverseTraversal(A);
    cout << "Size: " << sizeDLL(A) << endl;
    insertAtPosition(A, 90, 4);
    traversel(A);
    reverseTraversal(A);
    deleteAtPosition(A, 4);
    traversel(A);
    reverseTraversal(A);
    deleteAtPosition(A, 1);
    traversel(A);
    reverseTraversal(A);
    deleteAtPosition(A, sizeDLL(A));
    traversel(A);
    reverseTraversal(A);
    cout << "Final Size: " << sizeDLL(A) << endl;
}


