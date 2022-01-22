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
    TreeNode* solve(vector<int> &pre, int *st, vector<int> &in, int s, int e, map<int,int> &m){
        if(s > e)
            return NULL;
        TreeNode* root = new TreeNode(pre[*st]);
        int pos = m[pre[*st]];
        (*st)++;
        //cout << st << " ";
        root->left = solve(pre,st,in,s,pos-1,m);
        root->right = solve(pre,st,in,pos+1,e,m);
        //cout << "\n";
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        vector<int> in = pre;
        sort(in.begin(),in.end());
        
        map<int,int> m;
        for(int i = 0; i < in.size(); i++){
            m[in[i]] = i;
        }
        int st = 0;
        return solve(pre,&st,in,0,in.size()-1,m);
    }
};