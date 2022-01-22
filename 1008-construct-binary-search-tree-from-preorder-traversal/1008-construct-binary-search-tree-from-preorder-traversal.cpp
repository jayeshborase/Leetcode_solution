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
    // Approch First
    TreeNode* solve(vector<int> &pre, int *st, vector<int> &in, int s, int e, map<int,int> &m){
        if(s > e)
            return NULL;
        TreeNode* root = new TreeNode(pre[*st]);
        int pos = m[pre[*st]];
        (*st)++;
        
        root->left = solve(pre,st,in,s,pos-1,m);
        root->right = solve(pre,st,in,pos+1,e,m);
        
        return root;
    }
    
    // Approch 2nd
    TreeNode* solve2(vector<int> &p, int &s, int h){
        if(s == p.size() || p[s] > h) return NULL;
        
        TreeNode* root = new TreeNode(p[s]);
        s++;
        
        root->left = solve2(p,s,root->val);
        root->right = solve2(p,s,h);
        
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
        return solve2(pre,st,INT_MAX);//solve(pre,st,in,0,in.size()-1,m);
    }
};