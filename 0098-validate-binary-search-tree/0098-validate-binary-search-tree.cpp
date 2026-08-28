// Approach : I will just check that the values of the right and left subtrees
// for any root is correct or not then make calls for both the sides and keep on
// doing until it ends
// have to use postorder
// i was wrong can't even use postorder here have to use inorder here and check
// for sorting

class Solution {
public:
    TreeNode* prev = nullptr;
    bool helper(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        if (!helper(root->left)) {
            return false;
        }
        if (prev != nullptr) {
            if (prev->val >= root->val) {
                return false;
            }
        }
        // make previous as current node
        prev = root;
        if (!helper(root->right)) {
            return false;
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        // re initalize the global variable one more time to avoid any backend
        // issues
        prev = nullptr;
        return helper(root);
    }
};