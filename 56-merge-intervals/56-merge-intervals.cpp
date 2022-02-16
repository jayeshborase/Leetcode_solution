class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
       int s= intervals.size();
        vector<vector<int>> v;
        sort(intervals.begin(),intervals.end());
        int left, right;
        for (int i = 0; i < s; i++)
        {
            left = intervals[i][0];
            right = intervals[i][1];
            while (i < s-1 && right >= intervals[i+1][0])
            {
                right = max(right,intervals[i+1][1]);
                i++;
            }
            v.push_back({left,right});   
        }
        return v;
    }
};