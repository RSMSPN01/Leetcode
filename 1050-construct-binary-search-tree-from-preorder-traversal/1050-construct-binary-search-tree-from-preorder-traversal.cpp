// So the questions is simply asking me to create a BST from an array and i can
// do that its a easy question though, there are two ways first is by sorting
// the array then apply binary search and make the tree same we did make the
// tree out of the array, but it takes extra time O(nlogn) so instead i will
// directly create each node and just check that current value is larger or
// smaller then the root and make the calls accordingly
class Solution {
public:
    void helper(TreeNode* root, int x) {
        // each time simply add the value to the given root tree
        if (x < root->val) {
            // if smaller go left into left subtree
            if (root->left != nullptr) {
                helper(root->left, x);
            } else {
                // if it is null then create a new node and attach
                TreeNode* node = new TreeNode(x);
                root->left = node;
            }
        } else {
            // go to the right subtree
            if (root->right != nullptr) {
                helper(root->right, x);
            } else {
                // attach to the right side
                TreeNode* node = new TreeNode(x);
                root->right = node;
            }
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for (int i = 1; i < preorder.size(); i++) {
            // attach one by one
            helper(root, preorder[i]);
        }
        return root;
    }
};