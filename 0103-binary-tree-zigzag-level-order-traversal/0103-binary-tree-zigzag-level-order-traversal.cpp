// Approach : Same approach as used in printing the BFS just this time every
// even node is stored in a reverse manner that is it
class Solution {
public:
    void BFS(TreeNode* root, vector<vector<int>>& result) {
        // root is pushed in first
        queue<TreeNode*> temp;
        temp.push(root);
        int level = 0;
        while (!temp.empty()) {
            vector<int> levelVal;
            int n = temp.size();
            for (int i = 0; i < n; i++) {
                TreeNode* curntRoot = temp.front();
                // remove the root
                temp.pop();
                // store the child first
                if (curntRoot->left != nullptr) {
                    temp.push(curntRoot->left);
                }
                if (curntRoot->right != nullptr) {
                    temp.push(curntRoot->right);
                }
                // store the root then
                levelVal.push_back(curntRoot->val);
            }
            // check level is odd or even
            if (level & 1) {
                // reverse first then store it
                reverse(levelVal.begin(), levelVal.end());
            }
            result.push_back(levelVal);
            level++;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> result;
        BFS(root, result);
        return result;
    }
};