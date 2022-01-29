class Solution {
public:
    void rigmin(vector<int> &h, vector<int> &v){
        stack<pair<int,int>> s;
        
        for(int i = h.size()-1; i >= 0; i--){
            while(!s.empty() && s.top().first >= h[i]){
                s.pop();
            }
            
            if(!s.empty())
                v.push_back(s.top().second);
            else
                v.push_back(h.size());
            s.push({h[i],i});
        }
        reverse(v.begin(),v.end());
    }
    
    void lefmin(vector<int> &h, vector<int> &v){
        stack<pair<int,int>> s;
        
        for(int i = 0; i < h.size(); i++){
            while(!s.empty() && s.top().first >= h[i]){
                s.pop();
            }
            
            if(!s.empty())
                v.push_back(s.top().second);
            else
                v.push_back(-1);
            s.push({h[i],i});
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> l,r;
        lefmin(heights,l);
        rigmin(heights,r);
        
        int mx = INT_MIN;
        
        for(int i = 0; i < l.size(); i++){
            int len = (r[i]-1)-(l[i]+1)+1;
            cout << len << " ";
            mx = max(mx,len*heights[i]);
        }
        
        return mx;
    }
};