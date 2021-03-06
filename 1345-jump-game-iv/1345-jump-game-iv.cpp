class Solution {
public:
    int minJumps(vector<int>& arr) {        
        unordered_multimap<int,int> mmap;
        for(int i = 0; i < arr.size(); i++) {
            mmap.insert({arr[i],i});
        }
    
        int end = arr.size() - 1;
        vector<bool> visited(arr.size(), false);
        vector<int> step(arr.size(), 0);
        queue<int> q; 
        visited[0] = true;
        step[0] = 0;
        q.push(0);
        
        while(!q.empty()) {
            int i = q.front();            
            q.pop();
            
            if(i == end) {
               return step[i]; 
            }
            
            if( i+1 < arr.size() && visited[i+1] == false) {
                visited[i+1] = true;
                step[i+1] = step[i] + 1;
                q.push(i+1);
            } 
            if( i-1 >= 0 && visited[i-1] == false) {
                visited[i-1] = true;
                step[i-1] = step[i] + 1;
                q.push(i-1);                    
            }
            
            if(mmap.find(arr[i]) != mmap.end()) {
                auto p = mmap.equal_range(arr[i]);
                for (auto it = p.first; it != p.second; ++it) {
                    int j = it->second;
                    if(i!=j && visited[j] == false) {
                        visited[j] = true;
                        step[j] = step[i] + 1;
                        q.push(j);
                    }
                }
                mmap.erase(arr[i]);
            }           
        }
        return 0;
    }
};