#include <iostream>
#include <queue>
#include <limits.h>
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

void preorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void inorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}
void postorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val << " ";
}

int minInBST(Node *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->val;
}

int maxInBST(Node *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->val;
}

bool searchInBST(Node *root, int target)
{
    // base case
    if (root == NULL)
    {
        return false;
    }

    // case 1 agar target mil gaya.
    if (root->val == target)
    {
        return true;
    }
    // other cases
    bool leftAns = false;
    bool rightAns = false;
    // Agar target current root ke value se chota hai.
    if (root->val > target)
    {
        leftAns = searchInBST(root->left, target);
    }
    // Agar target current root ke value se bada hai.
    else if (root->val < target)
    {
        rightAns = searchInBST(root->right, target);
    }
    // yaha tak aayega hee nahi.
    return leftAns + rightAns;
}

Node *deleteInBST(Node *&root, int target)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->val == target)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            Node *leftSubtree = root->left;
            delete root;
            return leftSubtree;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            Node *rightSubtree = root->right;
            delete root;
            return rightSubtree;
        }
        else if (root->left != NULL && root->right != NULL)
        {
            int temp = maxInBST(root->left);
            root->val = temp;
            root->left = deleteInBST(root->left, temp);
            return root;
            // or

            // int temp = minInBST(root->right);
            // root->val = temp;
            // return deleteInBST(root->right, temp);
        }
    }
    if (root->val > target)
    {
        root->left = deleteInBST(root->left, target);
    }
    else if (root->val < target)
    {
        root->right = deleteInBST(root->right, target);
    }
    return root;
}

int main()
{
    Node *root = NULL; // Initialize root to NULL
    createBST(root);
    cout << "levelOrder Traversal: " << endl;
    levelOrderTraversal(root);
    cout << "preOrder Traversal: " << endl;
    preorderTraversal(root);
    cout << endl;
    cout << "inOrder Traversal: " << endl;
    inorderTraversal(root);
    cout << endl;
    cout << "postOrder Traversal: " << endl;
    postorderTraversal(root);
    cout << endl;
    cout << "smallest element in BST: " << endl;
    cout << minInBST(root) << endl;
    cout << "largest element in BST: " << endl;
    cout << maxInBST(root) << endl;

    int t;
    cout << "Enter the target: " << endl;
    cin >> t;

    while (t != -1)
    {
        bool ans = searchInBST(root, t);
        if (ans == true)
        {
            cout << t << " Found" << endl;
        }
        else
        {
            cout << t << " not Found" << endl;
        }
        cout << "Enter the target: " << endl;
        cin >> t;
    }

    int del;
    cout << "enter element to delete from BST: ";
    cin >> del;

    while (del != -1)
    {
        root = deleteInBST(root, del);
        cout << "after deletion of node " << del << " : " << endl;
        levelOrderTraversal(root);
        cout << endl;
        cout << "enter element to delete from BST: ";
        cin >> del;
    }
    return 0;
}
