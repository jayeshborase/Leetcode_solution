class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        
        for(auto i : nums){
            m[i]++;
        }
        int co = 0;
        for(auto i : nums){
            if(k == 0){
                if(m[i] > 1){
                    co += 1;
                    m[i] = 0;
                }
            }else{
                if(m.find(i+k) != m.end() && m[i] > 0){
                    co++;
                    m[i] = 0;
                }
            }
        }
        
        return co;
    }
};