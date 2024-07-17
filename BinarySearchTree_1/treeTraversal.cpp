#include<iostream>
using namespace std;

#include<iostream>
using namespace std;

class Node{
    
    public:
    int data;
    Node* left;
    Node* right;

    Node(int _data){
        this->data = _data;
        this->left = NULL;
        this->right = NULL;
    }
};


Node* createtree(){
    cout << "Enter Data : ";
    int data;
    cin >> data;

    if (data==-1)
    {
        return NULL;
    }
    //Step1 : Create Node;
    Node* root = new Node(data);
    //Step2 : Create Left Subtree;
    cout << "Enter the value for left Node of " << root->data << ": " << endl;
    root->left = createtree();
    //Step2 : Create right Subtree;
    cout << "Enter the value for right Node of " << root->data << ": " << endl;
    root->right = createtree();
    return root;
}

void preOrder(Node* t){
    //base case
    if (t==NULL)
    {
        return;
    }
    //NLR

    //N : current node
    cout << t->data << " ";
    //L
    preOrder(t->left);
    //R
    preOrder(t->right);
}

void inOrder(Node* t){
    //base case
    if (t==NULL)
    {
        return;
    }
    //LNR
    //L
    inOrder(t->left);
    //N
    cout << t->data << " ";
    //R
    inOrder(t->right);
}

void postOrder(Node* t){
    //base case
    if (t==NULL)
    {
        return;
    }
    //LRN

    //L
    postOrder(t->left);
    //R
    postOrder(t->right);
    //N
    cout << t->data << " ";
}

int main(){
    Node* tree = createtree();
    cout << "Preorder Traversal : " << endl;
    preOrder(tree);
    cout << endl;
    cout << "Inorder Traversal : " << endl;
    inOrder(tree);
    cout << endl;
    cout << "Postorder Traversal : " << endl;
    postOrder(tree);
    cout << endl;
}