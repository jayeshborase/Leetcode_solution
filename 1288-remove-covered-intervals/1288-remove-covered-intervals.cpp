class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(intervals.begin(),intervals.end());
        //vector<pair<int,int>> v;
        int left = intervals[0][0];
        int right = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            
            if(intervals[i][0] > left && intervals[i][1] > right){
              
                left = intervals[i][0];
                //i++;
                ans++;
            }
             right = max(right, intervals[i][1]);
            
        }
        
        return ans+1;//v.size();
    }
};