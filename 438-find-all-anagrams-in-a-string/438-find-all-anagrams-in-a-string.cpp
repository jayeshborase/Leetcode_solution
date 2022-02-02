class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> m;
        for(auto i : p){
            m[i]++;
        }
        int count = m.size();
        int i =0, j = 0;
        vector<int> ans;
        while(j < s.length()){
            if(m.find(s[j]) != m.end()){
                m[s[j]]--;
                cout << m[s[j]] << "/ " << count << "- ";
                if(m[s[j]] == 0)
                    count--;
            }
            
            if(j-i+1 < p.length())
                j++;
            else if(j-i+1 == p.length()){
                
                if(count == 0)
                    ans.push_back(i);
             
                if(m.find(s[i]) != m.end()){
                    if(m[s[i]] == 0)
                        count++;
                    m[s[i]]++;
                }
               
                i++;
                j++;
            }
        }
        
        return ans;
    }
};