// Approach : So i am finding the height for the root node so simply i will call
// the recursion for both side and they will return me there own heights/ depths
// so i will directly return that plus 1 for the level

// I also need to check for the leaf node if it is the leaf node then don't call

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right) + 1;
    }
};