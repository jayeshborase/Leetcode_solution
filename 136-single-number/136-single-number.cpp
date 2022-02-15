class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int temp = nums[0];
        int co = 1;
        for(int i = 1; i < nums.size(); i++){
            if(temp != nums[i]){
                if(co == 1){
                    break;
                }
                temp = nums[i];
                co = 1;
            }else{
                co++;
            }
        }
        return temp;
    }
};