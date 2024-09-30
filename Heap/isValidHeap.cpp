#include<iostream>
#include<algorithm>
#include<queue>
#include<limits.h>
using namespace std;

// Define the structure of the tree node
struct Node {
    int val;
    Node* left;
    Node* right;
    
    Node(int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};

// Function to check if the binary tree is a valid max-heap
pair<int, bool> isValidHeap(Node* head) {
    // Base case: If the node is null, return the smallest integer and true
    if(head == NULL) {
        return make_pair(INT_MIN, true);
    }
    
    // If the node is a leaf, return its value and true
    if(head->left == NULL && head->right == NULL) {
        return make_pair(head->val, true);
    }
    
    // Recursively check the left and right subtrees
    pair<int, bool> pair1 = isValidHeap(head->left);
    pair<int, bool> pair2 = isValidHeap(head->right);
    
    // If both the left and right subtrees are valid heaps and the current node value is greater than its children
    if(pair1.second == true && pair2.second == true && 
       (head->left == NULL || pair1.first < head->val) && 
       (head->right == NULL || pair2.first < head->val)) {
        return make_pair(head->val, true);
    } 
    else {
        // If the heap property is violated, return the max value and false
        return make_pair(max(head->val, max(pair1.first, pair2.first)), false);
    }
}

int main() {
    // Example to test the heap validation
    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(79);
    root->left->right = new Node(6);
    
    pair<int, bool> result = isValidHeap(root);
    
    if(result.second) {
        cout << "The binary tree is a valid max-heap." << endl;
    } else {
        cout << "The binary tree is NOT a valid max-heap." << endl;
    }
    
    return 0;
}
