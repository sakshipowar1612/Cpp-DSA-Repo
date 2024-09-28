#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int _val){
        this->val = _val;
        this->left = NULL;
        this->right = NULL; 
    }
};


Node* createTreeUsingInorder(vector<int>inorder, int inStart, int inEnd){
    if (inStart > inEnd)
    {
        return NULL;
    }
    
    int mid = (inStart+inEnd)/2;
    Node* root = new Node(inorder[mid]);
    root->left = createTreeUsingInorder(inorder, inStart, mid-1);
    root->right = createTreeUsingInorder(inorder, mid+1, inEnd);
    return root;
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

int main(){
    vector<int>vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);
    vec.push_back(60);
    vec.push_back(70);
    vec.push_back(80);

    Node* root = createTreeUsingInorder(vec, 0, vec.size()-1);
    levelOrderTraversal(root);
}


