#include <iostream>
#include <queue>
using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int _data)
    {
        this->data = _data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createtree()
{
    cout << "Enter Data : ";
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }
    // Step1 : Create Node;
    Node *root = new Node(data);
    // Step2 : Create Left Subtree;
    cout << "Enter the value for left Node of " << root->data << ": " << endl;
    root->left = createtree();
    // Step2 : Create right Subtree;
    cout << "Enter the value for right Node of " << root->data << ": " << endl;
    root->right = createtree();
    return root;
}


int height(Node *tree){
    if (tree==NULL)
    {
        return 0;
    }
    
    return 1+max(height(tree->left),height(tree->right));
}

int maxDepth(Node* tree){
    if (tree==nullptr)
    {
        return 0;
    }
    queue<Node*>q;
    q.push(tree);
    q.push(nullptr);
    int maxDepth=0;
    while (!q.empty())
    {
        Node* front = q.front();
        q.pop();
        if (front==nullptr)
        {
            maxDepth++;
            if (!q.empty())
            {
                q.push(nullptr);
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
    
    return maxDepth;
}

int lOTmaxheight(Node* tree){
    if(tree==NULL)return 0;
    queue<Node*>q;
    q.push(tree);
    int height = 0;
    while (!q.empty())
    {
        int size = q.size();
        for(int i=0; i<size; i++){
            Node* node = q.front();
            q.pop();
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
        }
        height++;
    }
    return height;
}

int main()
{
    // Example usage:
    Node *root = createtree();

    // levelWiseTraversal(root);
    cout << maxDepth(root)<< endl;
    cout << lOTmaxheight(root);
    return 0;
}
