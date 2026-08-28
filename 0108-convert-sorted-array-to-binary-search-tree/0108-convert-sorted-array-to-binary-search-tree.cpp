// Approach : Apply normal binary search and create the tree but i have to look
// what to return in the end after each call
class Solution {
public:
    TreeNode* helper(int l, int r, vector<int>& nums) {
        if (l <= r) {
            int mid = (l + r) / 2;
            TreeNode* newNode = new TreeNode(nums[mid]);
            newNode->left = helper(l, mid - 1, nums);
            newNode->right = helper(mid + 1, r, nums);
            return newNode;
        }
        return nullptr;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // no need for this extra node directly return
        // TreeNode* newNode = new TreeNode(0);
        // newNode->left = helper(0, nums.size() - 1, nums);
        // newNode->right = nullptr;
        return helper(0, nums.size() - 1, nums);
    }
};