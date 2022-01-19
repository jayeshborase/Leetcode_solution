class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int> m;
        
        for(auto i : s){
            m[i]++;
        }
        int i = m[s[0]];
        
        for(auto x : m){
            if(i != x.second)
                return 0;
        }
        
        return 1;
    }
};