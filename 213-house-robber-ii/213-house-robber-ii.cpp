class Solution {
public:
    int maxAmtspac(vector<int> &nums, int in){
        int pre1 = nums[0];
        int pre2 = 0;
        int maxAmt = nums[0];
        
        for(int i = 1; i < in; i++){
            int pick = nums[i] + pre2;
            int nonPick = 0 + pre1;
            
            maxAmt = max(pick,nonPick);
            
            pre2 = pre1;
            pre1 = maxAmt;
        }
        
        return maxAmt;
    }
    int rob(vector<int>& nums) {
        int si = nums.size();
        vector<int> temp1, temp2;
        if(si == 1) return nums[0];
        for(int i = 0; i < si; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != si-1) temp2.push_back(nums[i]); 
        }
        
        return max(maxAmtspac(temp1,temp1.size()), maxAmtspac(temp2,temp2.size()));
    }
};