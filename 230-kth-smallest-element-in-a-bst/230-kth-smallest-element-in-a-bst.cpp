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
    void solve(TreeNode* root, int &ans, int &c){
        if(root == NULL)
            return;
        solve(root->left,ans,c);
        c--;
        if(c == 0)
            ans = root->val;
        solve(root->right,ans,c);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        solve(root, ans, k);
        return ans;
    }
};