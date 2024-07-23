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

int main(){
    createtree();
}