class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        
        int si = f.size();
        int co = 0;
        // if(si == 1)
        //     return (f[0] == 0 && n == 1) || (f[0] == 1 && n == 0) || (f[0] == 0 && n == 0);
        
        for(int i = 0; n != 0 && i < si; i++){
            if(f[i] == 0){
                int prev = (i == 0 || f[i-1] == 0)?0:1;
                int next = (i == si-1 || f[i+1] == 0)?0:1;
              
                if(prev == 0 && next == 0){
                    f[i] = 1;
                    n--;
                }    
            }
        }
        
        if(n == 0)
            return 1;
        return 0;
    }
};