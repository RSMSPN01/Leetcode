// Approach: So i do get the idea about how we are going to solve this first
// find the root in the preorder then go and check that same root in inorder
// that will give us the nodes to how much goes to right and how much on left,
// but the real problem here is the implementation of this which idk how to?

// steps : Pick the first value from the preorder
// then search in inorder for the value, this will give us left and right nodes
// now again call both the functions for right and left passing the values
// i don't have any idea about converting them in code
class Solution {
public:
    TreeNode* helper(vector<int>& preorder, int preSt, int preEnd, vector<int>& inorder, int inSt, int inEnd, unordered_map<int, int>& inMap) {
        // base case run till only one node is left
        if (preSt > preEnd || inSt > inEnd) {
            return nullptr;
        }
        // first root
        TreeNode* root = new TreeNode(preorder[preSt]);
        int indx = inMap[root->val];
        int len = indx - inSt; // gives me lenght of left tree
        root->left = helper(preorder, preSt + 1, preSt + len, inorder, inSt, indx - 1, inMap);
        root->right = helper(preorder, preSt + 1 + len, preEnd, inorder, indx + 1, inEnd, inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        // to search value in contant time take hash map
        unordered_map<int, int> inMap;
        for (int i = 0; i < n; i++) {
            inMap[inorder[i]] = i;
        }
        return helper(preorder, 0, n - 1, inorder, 0, n - 1, inMap);
    }
};