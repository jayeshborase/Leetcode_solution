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

// TC - O(n+m) + (n+m)log(n+m);
// SC - O(n+m);
class Solution {
public:
    void solve(TreeNode* r1, vector<int>&v){
        if(r1 == NULL)
            return;
     
        solve(r1->left,v);
       
        v.push_back(r1->val);

        solve(r1->right,v);
    }
    vector<int> marge(vector<int> &v1, vector<int> &v2){
        int siz1 = v1.size();
        int siz2 = v2.size();
        int i = 0, j = 0;
        vector<int> v;
        
        while(i < siz1 && j < siz2){
            if(v1[i] < v2[j])
                v.push_back(v1[i++]);
            else
                v.push_back(v2[j++]);
        }
        
        while(i < siz1){
            v.push_back(v1[i++]);
        }
        
        while(j < siz2){
            v.push_back(v2[j++]);
        }
        
        return v;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2;
        solve(root1,v1);
        solve(root2,v2);
        return marge(v1,v2);
    }
};