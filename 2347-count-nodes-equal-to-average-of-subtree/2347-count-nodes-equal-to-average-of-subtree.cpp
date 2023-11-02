// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
// int avg(TreeNode* root)
//    { if(root->left==NULL&&root->right==NULL)
//          return root->val;
//        double sum = 0.0;
//         int count = 0;
//         queue<TreeNode*> q;
//         q.push(root);

//         while (!q.empty()) {
//             TreeNode* node = q.front();
//             q.pop();

//             sum += node->val;
//             count++;

//             if (node->left) {
//                 q.push(node->left);
//             }
//             if (node->right) {
//                 q.push(node->right);
//             }
//         }
//          cout<<sum<<"  "<<"  "<<count<<endl;
//         return sum / count;
//         }

//     int averageOfSubtree(TreeNode* root) {
//          if(root->left==NULL&&root->right==NULL)
//          return root->val;
//         queue<TreeNode*>q;
//         q.push(root);
//         vector<int>store;
//         int x;
//     while(!q.empty())
//     {
//         TreeNode* top=q.front();
//          int ans=avg(top);

//         if(ans==top->val)
//         x=top->val;
//         q.pop();
//         if(top->left)
//         q.push(top->left);
//         if(top->right)
//         q.push(top->right);
//     }
//   return x;
//     }
// };
class Solution {
 public:
  int averageOfSubtree(TreeNode* root) {
    int ans = 0;
    dfs(root, ans);
    return ans;
  }

 private:
  pair<int, int> dfs(TreeNode* root, int& ans) {
    if (root == nullptr)
      return {0, 0};
    const auto [leftSum, leftCount] = dfs(root->left, ans);
    const auto [rightSum, rightCount] = dfs(root->right, ans);
    const int sum = root->val + leftSum + rightSum;
    const int count = 1 + leftCount + rightCount;
    if (sum / count == root->val)
      ++ans;
    return {sum, count};
  }
};
