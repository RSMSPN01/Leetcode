// So basically in this we just have to add the previous number and that can be
// done using inorder travesal but that to be in the reverse order

// This could also be done using moris traversal in constant space but i will
// not solve that for now i have solved pretty much same questions earlier
class Solution {
public:
    int maxVal = 0;
    void helper(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        // reverse inorder
        // right
        helper(root->right);
        // calculate
        root->val = root->val + maxVal;
        maxVal = root->val;
        // left
        helper(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        maxVal = 0;
        helper(root);
        return root;
    }
};