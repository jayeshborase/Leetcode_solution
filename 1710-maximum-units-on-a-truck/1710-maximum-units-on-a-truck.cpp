class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        
        int ans = 0, count = 0;
        for(auto i : boxTypes){
            if(count == truckSize)
                break;
            
            int boxs = i[0];
            int unit = i[1];
            
            if((boxs+count) <= truckSize){
                ans += boxs*unit;
                count += boxs;
            }else{
                ans += unit*(truckSize-count);
                count = truckSize;
            }
            
        }
        return ans;
    }
};