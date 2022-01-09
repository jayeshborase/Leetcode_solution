class Solution {
public:
    void setZeroes(vector<vector<int>>& ma) {
        int c = ma[0].size();
        int r = ma.size();
        
        vector<pair<int,int>> v;
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(ma[i][j] == 0){
                    v.push_back({i,j});
                    cout << i << " " << j << " \n";
                }
                    
            }
        }
        
        for(auto p : v){
            int i = p.first;
            int j = p.second; 
            int index = 0;  
            int mx = max(r,c);
 
            while(index < mx){
                
                if(index < c)
                    ma[i][index] = 0;
          
                if(index < r)
                    ma[index][j] = 0;
                
                index++;
            }
        }
    }
};