/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
          unordered_map<TreeNode*, TreeNode*> parentMap;
        queue<TreeNode*> q;
        
        // BFS to create the parent map
        q.push(root);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if (temp->left) {
                parentMap[temp->left] = temp;
                q.push(temp->left);
            }
            if (temp->right) {
                parentMap[temp->right] = temp;
                q.push(temp->right);
            }
        }
        
        // BFS from the target node to find all nodes at distance k
        q.push(target);
        unordered_set<TreeNode*> visited;
        visited.insert(target);
        
        while (k > 0) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                
                if (temp->left && visited.find(temp->left) == visited.end()) {
                    q.push(temp->left);
                    visited.insert(temp->left);
                }
                if (temp->right && visited.find(temp->right) == visited.end()) {
                    q.push(temp->right);
                    visited.insert(temp->right);
                }
                if (parentMap.find(temp) != parentMap.end() && visited.find(parentMap[temp]) == visited.end()) {
                    q.push(parentMap[temp]);
                    visited.insert(parentMap[temp]);
                }
            }
            k--;
        }
        
        vector<int> ans;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
        }
        
        return ans;
    } 
};