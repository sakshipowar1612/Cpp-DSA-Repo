#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int _val)
    {
        this->val = _val;
        this->left = nullptr;
        this->right = nullptr;
    }
};
Node* createtree(){
    cout << "Enter Data : ";
    int val;
    cin >> val;

    if (val==-1)
    {
        return NULL;
    }
    //Step1 : Create Node;
    Node* root = new Node(val);
    //Step2 : Create Left Subtree;
    cout << "Enter the value for left Node of " << root->val << ": " << endl;
    root->left = createtree();
    //Step2 : Create right Subtree;
    cout << "Enter the value for right Node of " << root->val << ": " << endl;
    root->right = createtree();
    return root;
}


void inorderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
    cout << endl;
}

void levelTraversal(Node *root)
{
    if (root == nullptr)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node == nullptr)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            cout << node->val << " ";
            if (node->left != nullptr)
            {
                q.push(node->left);
            }
            if (node->right != nullptr)
            {
                q.push(node->right);
            }
        }
    }
}

void leftViewUsingLevelOrder(Node* root){
    if(root==nullptr){
        return;
    }
    queue<Node*>q;
    q.push(root);
    q.push(nullptr);
    cout << root->val << " ";
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        if(front==nullptr){
             
            if (!q.empty())
            {
                cout << q.front()->val << " ";
                q.push(nullptr);
            }else{
                cout << endl;
            }
            
        }
        else{
            
            if (front->left!=nullptr)
            {
                q.push(front->left);
            }
            if (front->right!=nullptr)
            {
                q.push(front->right);
            }
            
        }
    }
}

void leftViewUsingRecursion(Node* root, int level, vector<int>&vec){
    if(root==nullptr){
        return;
    }
    if(level==vec.size()){
        vec.push_back(root->val);
    }
    leftViewUsingRecursion(root->left, ++level, vec);
    leftViewUsingRecursion(root->right,level, vec);
    
}

void rightViewUsingRecursion(Node* root, int level, vector<int>&vec){
    if(root==nullptr){
        return;
    }
    if(level==vec.size()){
        vec.push_back(root->val);
    }
    rightViewUsingRecursion(root->right, ++level, vec);
    rightViewUsingRecursion(root->left,level, vec);
    
}

void printVec(vector<int>vec){
    for(int i : vec){
        cout << i << " ";
    }
    cout << endl;
} 

int main()
{
    Node *root = createtree();
    inorderTraversal(root);
    cout << endl;
    levelTraversal(root);
    leftViewUsingLevelOrder(root);
    vector<int>leftView;
    leftViewUsingRecursion(root, 0, leftView);
    printVec(leftView);
    vector<int>rightView;
    rightViewUsingRecursion(root, 0, rightView);
    printVec(rightView);
}