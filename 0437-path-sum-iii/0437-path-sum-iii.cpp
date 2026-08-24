// Approch : So there is also a recursive approach in which for every node we
// will find out that for how many times it satisfy the condition but that will
// going to take two traversal of each nodes

// I am going to use the hash map method in here just as we use to do in arrays
class Solution {
public:
    int count = 0;
    void helper(TreeNode* root, int targetSum, long long cSum, unordered_map<long long, int>& m) {
        if (root == nullptr) {
            return;
        }
        int value = root->val;
        cSum += value;
        // if(cSum == targetSum) {
        //     count++; // found the sum directly
        // }
         if(m.find(cSum - targetSum) != m.end()) {
            count += m[cSum - targetSum]; // update the count acc to occrrence
        }
        // push the curnt Value in map
        m[cSum]++; 
        // now make call for right and left side
        helper(root->left,targetSum,cSum,m);
        helper(root->right,targetSum,cSum,m);
        // also update the map when returning back
        if(m[cSum] == 1){
            m.erase(cSum);
        }else{
            m[cSum]--;
        }
    }
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return 0;
        }
        unordered_map<long long, int> preSum;
        preSum[0]++; // push zero for same values
        helper(root, targetSum, 0, preSum);
        return count; // global variable
    }
};