class Solution {
public:
    void reverve(vector<int> &v, int s, int e){
        while(s < e){
            swap(v[s++],v[e--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int si = nums.size();
        k = k%si;
        reverve(nums,0,si-k-1);
        reverve(nums,si-k,si-1);
        reverve(nums,0,si-1);
    }
};