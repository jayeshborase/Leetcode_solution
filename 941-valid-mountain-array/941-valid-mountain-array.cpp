class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int si = arr.size();
        
        int s = 0;
        int e = si-1;
        int mid = s+(e-s)/2;
        
        while(s < e){
            if(arr[mid] <= arr[mid+1])
                s = mid+1;
            else
                e = mid;
            
            mid = s+(e-s)/2;
        }
        cout << arr[s] << " ";
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
    }
};