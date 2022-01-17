class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string> p;
        map<string,char> w;
        vector<string> v;
        s.push_back(' ');
        string ans;
        int co = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                v.push_back(ans);
                co++;
                ans = "";
            }else{
                ans.push_back(s[i]);
            }
        }
        
        if(co != pattern.length())
            return false;
        int i = 0;
        int j = 0;
        
        while(i < pattern.length() && j < v.size()){
            if(p.find(pattern[i]) == p.end() && w.find(v[j]) == w.end()){
                p[pattern[i]] = v[j];
                w[v[j]] = pattern[i];
            }else if(p[pattern[i]] != v[j] || w[v[j]] != pattern[i]){
                return false;
            }
            i++,j++;   
        }
        
        return true;
    }
};