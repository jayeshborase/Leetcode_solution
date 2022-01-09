class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> v;
        v.push_back({1});
        
        for(int i = 1; i < rowIndex+1; i++){
            vector<int> a;
            for(int j = 0; j < v[i-1].size(); j++){
                if(j == 0){
                    a.push_back(1);
                    continue;
                }
                a.push_back(v[i-1][j-1]+v[i-1][j]);
            }
            a.push_back(1);
            v.push_back(a);
        }
        
        return v[rowIndex];
    }
};