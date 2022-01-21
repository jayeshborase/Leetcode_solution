class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int st = gas.size()-1;
        int end = 0;
        int ans = gas[st]-cost[st];
        
        while(end < st){
            if(ans < 0){
                st--;
                ans += gas[st]-cost[st];
            }else{
                ans += gas[end]-cost[end];
                end++;
            }
        }
        return ans >= 0 ? st : -1;
    }
};