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
TreeNode* constTree(vector<int>& inorder,int is,int ie,vector<int>& postorder,int ps,int pe,unordered_map<int,int>&mp)
{
    if(is>ie||ps>pe)
    return NULL;
        int rootVal = postorder[pe];
        int index = mp[rootVal];
        int point = index - is;
        TreeNode* root = new TreeNode(rootVal);
    root->left=constTree(inorder,is,index-1,postorder,ps,ps+point-1,mp);
    root->right=constTree(inorder,index+1,ie,postorder,ps+point,pe-1,mp);
    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        int n =postorder.size();
        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;
        return constTree(inorder, 0, n - 1, postorder, 0, n - 1, mp);
    }
};