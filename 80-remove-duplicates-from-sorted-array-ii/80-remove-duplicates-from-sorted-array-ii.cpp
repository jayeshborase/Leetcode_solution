class Solution {
public:
    void remele(vector<int> &v, int s, int k){
        for(int i = s; i < v.size()-k; i++){
            v[i] = v[i+k];
        }
    }
    int removeDuplicates(vector<int>& nums) {
        int si = nums.size();
        int s = 0;
        for(int i = 0; i < si-2;i++){
            s = 0;
            int j = i;
            while(j+2 < si && nums[i] == nums[j+2]){
                j++;
                s++;
            }
            if(s > 0)
                remele(nums,i+2,s);
            si -= s;
        }
        
        return si;
    }
};