#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    vector<Node *> children; // Correct vector declaration

    Node(int _data)
    {
        this->data = _data;
    }
};

Node *createGeneralTree()
{
    int data;
    cout << "Enter data: ";
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    Node *root = new Node(data);
    
    cout << "Enter number of children for node " << root->data << ": ";
    int numChildren;
    cin >> numChildren;

    for (int i = 0; i < numChildren; ++i)
    {
        cout << "Enter data for child " << i + 1 << " of node " << root->data << ": ";
        root->children.push_back(createGeneralTree());
    }
    
    return root;
}

void printTree(Node *root, int level = 0)
{
    if (root == NULL)
    {
        return;
    }

    for (int i = 0; i < level; ++i)
    {
        cout << "  ";
    }
    cout << root->data << endl;

    for (Node *child : root->children)
    {
        printTree(child, level + 1);
    }
}

int main()
{
    Node *root = createGeneralTree();
    cout << "Tree structure:" << endl;
    printTree(root);
    return 0;
}
