#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertNode(Node *&root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return root;
    }
    if (val < root->val)
    {
        root->left = insertNode(root->left, val);
    }
    else if (val > root->val)
    {
        root->right = insertNode(root->right, val);
    }
    return root;
}

void createBST(Node *&root)
{
    int val;
    cout << "Enter value (-1 to stop): ";
    cin >> val;
    while (val != -1)
    {
        root = insertNode(root, val);
        cout << "Enter value (-1 to stop): ";
        cin >> val;
    }
}

void levelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->val << " ";
            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
    cout << endl;
}

// Inorder traversal to load values from the tree
void loadInorder(Node* head, vector<int> &inorder){
    if(head == NULL){
        return;
    }
    loadInorder(head->left, inorder);
    inorder.push_back(head->val);
    loadInorder(head->right, inorder);
}

// Level order traversal to assign values back to the nodes (reverse inorder for max-heap)
void assignValuesForMaxHeap(Node* head, vector<int>inorder, int &index){
    if(head == NULL){
        return;
    }
    assignValuesForMaxHeap(head->left, inorder, index);
    assignValuesForMaxHeap(head->right, inorder, index);
    head->val = inorder[index];
    index++;
}

// Convert BST to Max-Heap
void convertIntoMaxHeap(Node* head){
    if(head == NULL){
        return;
    }
    vector<int> inorder;
    
    // Step 1: Load inorder traversal of the BST
    loadInorder(head, inorder);
    
    // Step 2: Sort inorder in reverse order (for max-heap property)
    // sort(inorder.begin(), inorder.end(), greater<int>());
    
    // Step 3: Assign values back to the tree in level-order
    int index = 0;
    assignValuesForMaxHeap(head, inorder, index);
}

void assignValuesForMinHeap(Node* head, vector<int>inorder,int &index){
    if(head == NULL){
        return;
    }
    head->val = inorder[index];
    index++;
    assignValuesForMinHeap(head->left, inorder, index);
    assignValuesForMinHeap(head->right, inorder, index);
    
}

// Convert BST to Max-Heap
void convertIntoMinHeap(Node* head){
    if(head == NULL){
        return;
    }
    vector<int> inorder;
    
    // Step 1: Load inorder traversal of the BST
    loadInorder(head, inorder);
    
    // Step 2: Sort inorder in reverse order (for max-heap property)
    // sort(inorder.begin(), inorder.end(), greater<int>());
    for(int a: inorder){
        cout << a << " ";
    }
    cout << endl;
    // Step 3: Assign values back to the tree in level-order
    int index = 0;
    assignValuesForMinHeap(head, inorder, index);
}



int main(){
    cout << "First Binary Tree : " << endl;
    Node* tree1 = NULL; // Fix: Initialize tree to NULL
    createBST(tree1);
    cout << "BST (Level Order):" << endl;
    levelOrderTraversal(tree1);
    
    // Convert BST to Max-Heap
    cout << "MaxHeap: " << endl;
    convertIntoMaxHeap(tree1);
    cout << "Max-Heap (Level Order):" << endl;
    levelOrderTraversal(tree1);

    cout << "Second Binary Tree : " << endl;
    Node* tree2 = NULL; // Fix: Initialize tree to NULL
    createBST(tree2);
    cout << "BST (Level Order):" << endl;
    levelOrderTraversal(tree2);

    // Convert BST to Mix-Heap
    cout << "MinHeap: " << endl;
    convertIntoMinHeap(tree2);
    cout << "Max-Heap (Level Order):" << endl;
    levelOrderTraversal(tree2);

    return 0;
}
