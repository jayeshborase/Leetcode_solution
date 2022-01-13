class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int si = points.size();
        sort(points.begin(),points.end());
        for(auto x:points){
            cout << "[" << x[0] << " " << x[1] << "]\t";
        }
        
        int i = 0;
        int count = 0;
        vector<pair<int,int>> v;
        while(i < si){
            int le = points[i][0];
            int ri = points[i][1];
            int cri = ri;
            
            while(i < si-1 && ri >= points[i+1][0]){
                cri = max(cri,points[i+1][1]);
                cout << ri << "-" << points[i+1][0] << " ";
                if(points[i+1][1] < ri)
                    ri = points[i+1][1];
                i++;
            }
            cout << "\n";
            count++;
            v.push_back({le,cri});
            i++;
        }
        for(auto x:v){
            cout << x.first << " " << x.second << "\n";
        }
        return v.size();
    }
};