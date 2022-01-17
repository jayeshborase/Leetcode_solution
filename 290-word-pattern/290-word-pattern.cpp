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
            string a = s.substr(0,s.find(' '));
            s = s.substr(s.find(' ')+1,s.length());
            cout << a << " ";
            if(p.find(pattern[i]) == p.end() && w.find(a) == w.end()){
                p[pattern[i]] = a;
                w[a] = pattern[i];
            }else if(p[pattern[i]] != a || w[a] != pattern[i]){
                return false;
            }
            i++,j++;   
        }
        
        return true;
    }
};