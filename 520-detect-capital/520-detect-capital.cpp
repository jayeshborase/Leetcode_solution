class Solution {
public:
    bool detectCapitalUse(string word) {
        int sm = 0, ca = 0;
        for(auto i : word){
            if(i >= 'a' && i <= 'z')
                sm++;
            else
                ca++;
        }
        
        if(ca == word.length())
            return 1;
        else if(sm == word.length())
            return 1;
        else if(word[0] >= 'A' && word[0] <= 'Z' && sm == word.length()-1)
            return 1;
        
        return 0;
    }
};