// basic Approach from insert interval 
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int si = points.size();
        sort(points.begin(),points.end());
       
        int i = 0;
        int count = 0;
        while(i < si){
            int le = points[i][0];
            int ri = points[i][1];
            
            while(i < si-1 && ri >= points[i+1][0]){
                // only change here 
                //if(points[i+1][1] < ri)
                    ri = min(ri,points[i+1][1]);
                i++;
            }
            count++;
            i++;
        }
    
        return count;
    }
};