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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL)
            return new TreeNode(val);
        
        TreeNode* head = root;
        
        while(head->val < val ? head->right : head->left){
            head = head->val < val ? head->right : head->left;
        }
        
        if(head->left == NULL && head->val > val)
            head->left = new TreeNode(val);
        else if(head->right == NULL && head->val < val)
            head->right = new TreeNode(val);
        
        return root;
    }
};