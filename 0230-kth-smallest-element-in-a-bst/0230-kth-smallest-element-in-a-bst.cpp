// Approach : The most fastest i could think of is to do moris traversal and
// keep the count that how many numbers we have calculated when the count and k
// matches then we return that exact value right there but still that would cost
// a minimum of linear time

// one problem here is that we can't actaully modify the real tree it should
// remain as it is after doing operations so i will store the result and return
// that in the every end
class Solution {
public:
    void morisAlgo(TreeNode* root, int k, int& ans) {
        while (root != nullptr) {
            if (root->left != nullptr) {
                TreeNode* pred = root->left;
                while (pred->right != nullptr && pred->right != root) {
                    pred = pred->right;
                }
                if (pred->right == nullptr) {
                    // if null make conection & move left again
                    pred->right = root;
                    root = root->left;
                } else {
                    // visit & move right & break link too
                    k--;
                    if (k == 0) {
                        ans = root->val;
                    }
                    pred->right = nullptr;
                    root = root->right;
                }
            } else {
                // visit & move right
                k--;
                if (k == 0) {
                    ans = root->val;
                }
                root = root->right;
            }
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        morisAlgo(root, k, ans);
        return ans;
    }
};