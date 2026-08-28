// Approach : For any node to be LCA both the nodes should occur on the left and
// right subtree and that i will try to find out here
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return root;
        }
        // if any of the value is found in root then it is the LCA
        if (root->val == p->val || root->val == q->val) {
            return root;
        } else if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
        return nullptr;
    }
};