class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
//         set<vector<int>> s;
//         map<int,int> m;
        
//         for(auto i : nums){
//             m[i]++;
//         }
       
//         vector<vector<int>> ans;
//         for(int i = 0; i < nums.size(); i++){
//             m[nums[i]]--;
//             for(int j = i+1; j < nums.size(); j++){
//                 m[nums[j]]--;
//                 int c = -(nums[i]+nums[j]);
//                 if(m.find(c) != m.end()  &&  m[c] > 0){
//                     vector<int> t = {nums[i],nums[j],c};
//                     sort(t.begin(), t.end());
//                     s.insert(t);
//                 }
//                 m[nums[j]]++;
//             }
//             m[nums[i]]++;
//         }
        
//         ans.assign(s.begin(),s.end());
//         return ans;
        
        
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> ans;
        if(nums.size() < 3)
            return ans;
        
        for(int i = 0; i < nums.size()-2; i++){
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])){
                int lo = i+1;
                int hi = nums.size()-1;
                int c = 0-nums[i];

                while(lo < hi){
                    if(nums[lo] + nums[hi] == c){
                        vector<int> v = {nums[i],nums[lo],nums[hi]};
                        ans.push_back(v);

                        while(lo < hi && nums[lo] == nums[lo+1]) lo++;
                        while(lo < hi && nums[hi] == nums[hi-1]) hi--;

                        lo++;
                        hi--;
                    }else if((nums[lo]+nums[hi]) < c) lo++;
                    else hi--;
                }
            }
        }
        
        return ans;
    }
};