// Approach  : I can think for only the left side i can do that without using
// any issue what how to handle the right side is where it gets messy and i
// don't understand how to handle that even hint doesn't help so lets take some
// real help now

// this is kind of reverse post order traversal to solve the question from
// striver although we can solve this using stack too but i will use the more
// easy way

class Solution {
public:
    TreeNode* prev = nullptr;
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        // traverse right first
        flatten(root->right);
        // then to the left
        flatten(root->left);
        // on your way coming back update your right and left
        root->right = prev;
        root->left = nullptr;
        // and update the prev as curnt node
        prev = root;
    }
};