// Approach : So we have to use BFS in this but this time we need to treat the
// tree, as the root node is geeting from the given node from given input

// Few Steps to follow
// 1: First find the start node in the tree
// 2: Then make a map in which create the parent pointer for each node
// 3: Then traverse the map from start node and keep track of levels
// 4: return the max level in the end
class Solution {
public:
    // this will complete 1 and 2 step combined
    void helper1(TreeNode* root, int start, TreeNode*& R, unordered_map<TreeNode*, TreeNode*>& prnt) {
        if (root == nullptr) {
            return;
        }
        if (root->val == start) {
            R = root; // find the new starting node of tree
        }
        // i don't need this i have already check below for this
        // check this afterwards bcs leaf node could be the start
        // if (root->left == nullptr && root->right == nullptr) {
        //     return;
        // }
        if (root->left != nullptr) {
            prnt[root->left] = root;
            helper1(root->left, start, R, prnt);
        }
        if (root->right != nullptr) {
            prnt[root->right] = root;
            helper1(root->right, start, R, prnt);
        }
    }
    // Step 3 and 4 :
    int helper2(TreeNode* root, unordered_map<TreeNode*, int>& v, unordered_map<TreeNode*, TreeNode*>& prnt) {
        // apply bfs
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        v[root] = level;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left != nullptr && v.find(temp->left) == v.end()) {
                    q.push(temp->left);
                    v[temp->left] = level + 1;
                }
                if (temp->right != nullptr && v.find(temp->right) == v.end()) {
                    q.push(temp->right);
                    v[temp->right] = level + 1;
                }
                if (prnt.find(temp) != prnt.end() && v.find(prnt[temp]) == v.end()) {
                    q.push(prnt[temp]);
                    v[prnt[temp]] = level + 1;
                }
            }
            level++;
        }
        // so in the end last level elements will still left and that will lead
        // to one more false level count so return with 1 subtract
        return level - 1;
    }
    int amountOfTime(TreeNode* root, int start) {
        if (root == nullptr) {
            return 0;
        }
        unordered_map<TreeNode*, TreeNode*> parent; // Parent pointer
        TreeNode* newRoot = nullptr;
        helper1(root, start, newRoot, parent);
        // there is no need for storing the levels but just for understanding
        // purposes that is good
        unordered_map<TreeNode*, int> visited; // sotre levels
        return helper2(newRoot, visited, parent);
        // for(auto i : parent){
        //     cout<<i.first->val<<" "<<i.second->val<<"  ";
        // }
        // cout<<newRoot->val;
        // return 1;
    }
};