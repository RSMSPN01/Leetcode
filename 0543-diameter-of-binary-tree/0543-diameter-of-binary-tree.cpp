// Approach : So here i need to find out the height of left and right subtree
// from any root point and return the maximum of that

// Another way could be to take global variable and calculate height for every
// node as taking it root and return the max
class Solution {
public:
    int height(TreeNode* root) {
        if (root == nullptr ||
            (root->left == nullptr && root->right == nullptr)) {
            return 0;
        }
        return 1 + max(height(root->left), height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // check for leaf node as well
        if (root == nullptr ||
            (root->left == nullptr && root->right == nullptr)) {
            return 0;
        }
        // this will give the height for current root
        // extra check only go ahead for left or right side if there exist a
        // node else just don't call the function

        // calculate current node diameter
        int crntHeight = height(root->left) + height(root->right);
        // So this will add the height of the left joint and right joint only if
        // they exists
        if (root->left != nullptr)
            crntHeight++;
        if (root->right != nullptr)
            crntHeight++;
        // left subtree call
        int leftTreeHeight = diameterOfBinaryTree(root->left);

        // right subtree call
        int rightTreeHeight = diameterOfBinaryTree(root->right);

        // return the max out of these threes
        return max(crntHeight, max(leftTreeHeight, rightTreeHeight));
    }
};