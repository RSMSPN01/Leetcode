// Approach : So basically we need to find two given nodes and that can be done
// easily by taking any node as root node and traversing both the sides finding
// for that node but for every node we need to traverse the tree twice

// There must be a optimal solution to this to find the solution in just one
// pass
class Solution {
public:
    // This is whole functions logic is wrong though i don't really know to how
    // to fix this bool isFound(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     if (root == nullptr) {
    //         return false;
    //     }
    //     if (root == p || root == q) {
    //         return true;
    //     }
    //     return (isFound(root->left, p, q) && isFound(root->right, p, q));
    // }

    // going to use the video method now
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }
        TreeNode* leftTree = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightTree = lowestCommonAncestor(root->right, p, q);
        if (leftTree == nullptr) {
            return rightTree;
        } else if (rightTree == nullptr) {
            return leftTree;
        } else {
            return root;
        }
    }
};