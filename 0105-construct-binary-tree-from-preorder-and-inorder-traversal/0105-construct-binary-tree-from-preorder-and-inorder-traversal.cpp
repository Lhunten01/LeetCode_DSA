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
    TreeNode* constTree(vector<int>&preorder,int ps,int pe,vector<int>&inorder,int is,int ie,unordered_map<int,int>&mp)
    {
        if(is>ie||ps>pe)
        return NULL;
        TreeNode* root=new TreeNode(preorder[ps]);
        int index=mp[preorder[ps]];
        int leftEle=index-is;
        root->left=constTree(preorder,ps+1,ps+leftEle,inorder,is,index-1,mp);
        root->right=constTree(preorder,ps+leftEle+1,pe,inorder,index+1,ie,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        int n=preorder.size();
        for(int i=0;i<n;i++)
        mp[inorder[i]]=i;
        return constTree(preorder,0,n-1,inorder,0,n-1,mp);
    }
};