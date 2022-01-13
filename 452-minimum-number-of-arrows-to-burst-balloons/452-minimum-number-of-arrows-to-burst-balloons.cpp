// basic Approach from insert interval 
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int si = points.size();
        sort(points.begin(),points.end());
       
        int i = 0;
        int count = 0;
        while(i < si){
            int end = points[i][1];
            
            while(i < si-1 && end >= points[i+1][0]){
                // only change here Xend store minimum value
                end = min(end,points[i+1][1]);
                i++;
            }
            count++;
            i++;
        }
    
        return count;
    }
};