#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;


// Definition for a binary tree node
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Class to check if a binary tree is a complete binary tree (CBT)
class BinaryTree {
public:
    // Function for level order traversal and to check CBT condition
    void levelOrderTraversal(TreeNode* root, bool &isCBT) {
        if (root == NULL) {
            return;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        bool nullFound = false;

        // Perform level order traversal
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // If a null node is found, mark that subsequent nodes should not be non-null
            if (node == NULL) {
                nullFound = true;
            } else {
                // If a node is found after a null node, it's not a complete binary tree
                if (nullFound) {
                    isCBT = false;
                    break;
                }
                // Continue adding left and right children to the queue
                q.push(node->left);
                q.push(node->right);
            }
        }
    }

    // Function to check if the tree is a complete binary tree
    bool isCompleteTree(TreeNode* root) {
        bool isCBT = true;
        levelOrderTraversal(root, isCBT);
        return isCBT;
    }
};

int main() {
    // Creating the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    // Note: Uncommenting the line below makes it incomplete
    // root->right->right = new TreeNode(7); 

    BinaryTree tree;
    if (tree.isCompleteTree(root)) {
        cout << "The tree is a complete binary tree." << endl;
    } else {
        cout << "The tree is not a complete binary tree." << endl;
    }

    return 0;
}
