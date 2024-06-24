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
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,0});
        unsigned long long maxi=0;
        while(!q.empty())
        {   
           int n=q.size();
           unsigned long long first,last;
            for(int i=0;i<n;i++)
            { 
              
               auto it=q.front();
               root=it.first;
               unsigned long long index=it.second;
               if(i==0)
               first=index;
               if(i==n-1)
               last=index;
               q.pop();
               if(root->left)
               q.push({root->left,2*index+1});
                if(root->right)
               q.push({root->right,2*index+2});
            }
            maxi=max(maxi,last-first+1);
        }
        return maxi;
    }
};