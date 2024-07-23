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

void levelWiseTraversal(Node *tree)
{
    if (tree == nullptr)
        return; // If the tree is empty, return immediately.

    queue<Node *> q;
    q.push(tree);
    q.push(nullptr); // Marker for the end of the current level.

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front == nullptr)
        {
            cout << endl; // End of current level, start a new line.
                          // Marker for the next level.
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            cout << front->data << " ";
            if (front->left != nullptr)
                q.push(front->left);
            if (front->right != nullptr)
                q.push(front->right);
        }
    }
}

int main()
{
    // Example usage:
    Node *root = createtree();

    levelWiseTraversal(root);

    return 0;
}
