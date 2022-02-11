class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<long,long>> d;
        long sum = 0, ans = INT_MAX;
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            //cout << sum << " ";
            if(sum >= k){
                ans = min(ans,(long)i+1);
            }
            
            pair<long,long> p = {INT_MIN,INT_MIN};
            while(!d.empty() && sum-d.front().first >= k){
                p = d.front();
                //sum -= d.front().first;
                d.pop_front();
                
                 //cout << " -" << sum  << " " << d.front().first << " lo";
            }
            if(p.second != INT_MIN){
                ans = min(ans, i-p.second);
            }
                 
            while(!d.empty() && d.back().first >= sum){
                d.pop_back();
            }
            
            d.push_back({sum,i});
        }
        
        return ans != INT_MAX ? ans : -1;
    }
};