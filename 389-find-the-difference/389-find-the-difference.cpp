class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int> m;
        //sort(t.begin(),t.end());
        for(auto i : s){
            m[i]++;
        }
        char ch = NULL;
        for(auto i : t){
            if(m.find(i) == m.end()){
                ch = i;
                cout << i << " ";
            }else{
                m[i]--;
                if(m[i] == 0)
                    m.erase(i);
            }
             
        }
        
        return ch;
    }
};