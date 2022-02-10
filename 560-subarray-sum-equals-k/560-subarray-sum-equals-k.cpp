class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        
        int sum = 0;
        m[0] = 0;
     
        int co = 0;
        for(auto i : nums){
            sum += i;
            if(sum == k){
                co++;
            }
            
            if(m.find(sum-k) != m.end())
                co += m[sum-k];
            
            m[sum]++;
        }
        
        return co;
    }
};