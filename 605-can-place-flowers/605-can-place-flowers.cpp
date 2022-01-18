class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        
        int si = f.size();
        int co = 0;
        if(si == 1)
            return (f[0] == 0 && n == 1) || (f[0] == 1 && n == 0) || (f[0] == 0 && n == 0);
        
        for(int i = 0; n != 0 && i < si; i++){
            if(f[i] == 0){
                if(i == 0 ){
                    if(f[i+1] == 0){
                        n--;
                        f[i] = 1;
                    }
                }else if(i == si-1){
                    if(f[i-1] == 0){
                        n--;
                        f[i] = 1;
                    }
                }else
                    if(f[i-1] == 0 && f[i+1] == 0){
                        n--;
                        f[i] = 1;
                    }
                 
            }
           
        }
        
        if(n == 0)
            return 1;
        return 0;
    }
};