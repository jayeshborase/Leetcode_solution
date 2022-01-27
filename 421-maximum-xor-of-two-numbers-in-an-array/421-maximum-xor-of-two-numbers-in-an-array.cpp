class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxx=0, mask=0;
        for(int i=31; i>=0; i--) {
            mask = mask | (1<<i);
            unordered_set<int> s;
            for(auto &num : nums) s.insert(num & mask);
            int newMaxx = maxx | (1<<i);
            for(auto &prefix : s) {
                if(s.find(newMaxx^prefix)!=s.end()) {
                    maxx = newMaxx;
                    break;
                }
            }
        }
        return maxx;
    }
};

    