class Solution {
public:
    bool iseating(vector<int>& piles, int h, int mid){
        int to = 0;
        for(auto i:piles){
            to += i/mid;
            if(i%mid != 0) to++;
        }
        
        return to <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int e = 0;
        for(auto i:piles){
            e = max(e,i);
        }
        
        int s = 1;
        
        int mid = s+(e-s)/2;
        int ans = 0;
        while(s <= e){
            if(iseating(piles,h,mid)){
                e = mid-1;
                ans = mid;
            }else
                s = mid+1;
            
            mid = s+(e-s)/2;
        }
        
        return mid;
    }
};