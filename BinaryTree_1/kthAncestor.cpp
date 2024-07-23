#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

bool traverse(Node *root, int node, vector<int> &vec)
{
    if (root == nullptr)
    {
        return false;
    }
    vec.push_back(root->data);
    if (root->data == node)
    {
        return true;
    }

    if (traverse(root->left, node, vec) || traverse(root->right, node, vec))
    {
        return true;
    };
    vec.pop_back();
    return false;
}

int kthAncestor(Node *root, int k, int node)
{
    vector<int> path;
    bool found = traverse(root, node, path);
    if (!found || k >= path.size())
    {
        return -1;
    }
    return path[path.size() - k - 1];
}

int main()
{
    // Example to test the code
    Node *root = new Node{1, nullptr, nullptr};
    root->left = new Node{2, nullptr, nullptr};
    root->right = new Node{3, nullptr, nullptr};
    root->left->left = new Node{4, nullptr, nullptr};
    root->left->right = new Node{5, nullptr, nullptr};
    root->right->left = new Node{6, nullptr, nullptr};
    root->right->right = new Node{7, nullptr, nullptr};

    int k = 1;
    int node = 3;
    int ancestor = kthAncestor(root, k, node);

    if (ancestor != -1)
    {
        cout << "The " << k << "th ancestor of node " << node << " is " << ancestor << endl;
    }
    else
    {
        cout << "The " << k << "th ancestor of node " << node << " does not exist." << endl;
    }

    return 0;
}
