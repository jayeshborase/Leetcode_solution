class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char,string> p;
        map<string,char> w;
        s.push_back(' ');
    
        int i = 0;
        int j = 0;
        
        while(i < pattern.length() && s.length() != 0){
            string a = s.substr(0,s.find(' '));
            s = s.substr(s.find(' ')+1,s.length());
            cout << a << " -" << s << "- ";
            if(p.find(pattern[i]) == p.end() && w.find(a) == w.end()){
                p[pattern[i]] = a;
                w[a] = pattern[i];
            }else if(p[pattern[i]] != a || w[a] != pattern[i]){
                return false;
            }
            i++,j++;   
        }
        
        return s.length() == 0 && i == pattern.length()?true:false;
    }
};