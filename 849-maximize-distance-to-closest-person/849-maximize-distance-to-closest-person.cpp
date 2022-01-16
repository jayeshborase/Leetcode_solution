class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int si = seats.size();
        vector<int> l(si,-1),r(si,-1);
        
        int i = 0;
        int j = si-1;
        int in_l = -1;
        int in_r = -1;
        while(i < si && j >= 0){
            if(seats[i] == 1){
                in_l = i;
            }else{
                l[i] = in_l;
            }
            
            if(seats[j] == 1){
                in_r = j;
            }else{
                // if(in_r == -1){
                //     r[j] = j;
                // }else
                    r[j] = in_r;
            }
            i++;
            j--;
        }
        
        int mx = -1;
        i = 0;
        
        while(i < si){
            if(l[i] != -1 && r[i] != -1){
                int mid = l[i]+(r[i]-l[i])/2;
                mx = max(mx,min(abs(l[mid]-mid),abs(r[mid]-mid)));
            }else if(l[i] != -1){
                //int mid = l[i]+(i-l[i])/2;
                mx = max(mx,abs(l[i]-i));
            }else if(r[i] != -1){
                //int mid = i+(r[i]-i)/2;
                mx = max(mx,abs(r[i]-i));
            }
            i++;
        }
        
        return mx;
    }
};