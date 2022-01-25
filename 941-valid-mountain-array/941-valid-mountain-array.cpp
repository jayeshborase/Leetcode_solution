class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int si = arr.size();
        
        if(si < 3) return false;
        int s = 0;
        int e = si-1;
      
        while(s+1 < si-1 && arr[s] < arr[s+1]) s++;
        
        while(e-1 > 0 && arr[e] < arr[e-1]) e--;
        
        return s == e;
        
        /* 
        TC = O(n+logn)  sp = O(1)
        int mid = s+(e-s)/2;   
        while(s < e){
            if(arr[mid] <= arr[mid+1])
                s = mid+1;
            else
                e = mid;
            
            mid = s+(e-s)/2;
        }
     
        if(arr[s] == arr[0] || arr[s] == arr[si-1])
            return false;
        
        int j = s;
        for(int i = s-1; i >= 0; i--){
            if(arr[j] <= arr[i])
                return false;
            j--;
                
        }
        j = s;
        for(int i = s+1; i < si; i++){
            if(arr[j] <= arr[i])
                return false;
            j++;
                
        }
        
        return true;
        */
    }
};