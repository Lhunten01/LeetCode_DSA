/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:  unordered_map<int,int>mp;
  void dfs(TreeNode* root)
  {
      if(!root)
      return;
    
    dfs(root->left);
    mp[root->val]++;
    dfs(root->right);

  }
    vector<int> findMode(TreeNode* root) {
        dfs(root);
       vector<int>ans;
       int maxfreq=0;
       for(auto it:mp)
       {
           if(it.second>maxfreq)
           {
               ans={};
               ans.push_back(it.first); 
               maxfreq=it.second; 
           }
         else  if(it.second==maxfreq)
           {
               ans.push_back(it.first); 
           }
       }
       return ans;
    }
};