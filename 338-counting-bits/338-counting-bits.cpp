class Solution {
public:
    int bina(int n){
        int co = 0;
        while(n != 0){
            if(n&1){
               co++; 
            }
            n = n>>1;
        }
        return co;
    }
    vector<int> countBits(int n) {
        vector<int> v(1,0);
        
        for(int i = 1; i <= n; i++){
            v.push_back(bina(i));
        }
        return v;
    }
};