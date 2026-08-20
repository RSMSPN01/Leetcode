// Approach : So it just difference between the two subtrees so that what i will
// do , 1st i will find out the height of both the subtree then check if that
// exceeds the limit or not if not then keep going else return false

class Solution {
public:
    int height(TreeNode* root) {
        if (root == nullptr ||
            (root->left == nullptr && root->right == nullptr)) {
            return 0;
        }
        return 1 + max(height(root->left), height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        // if reached to leaf node means we are good
        if (root->left == nullptr && root->right == nullptr) {
            return true;
        }
        // add that extra left over connected node with root
        int leftNode = height(root->left);
        int rightNode = height(root->right);
        if (root->left != nullptr) {
            leftNode++;
        }
        if (root->right != nullptr) {
            rightNode++;
        }
        // check the positive difference
        if (abs(leftNode - rightNode) > 1) {
            return false;
        }
        // calling both the left out subtrees
        return (isBalanced(root->left) && isBalanced(root->right));
    }
};