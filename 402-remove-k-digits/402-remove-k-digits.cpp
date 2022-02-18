class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char> d;
        
        int i = 0;
        while(i < num.length()){
            while(k != 0 && !d.empty()  && d.back() > num[i]){
                k--;
                d.pop_back();
            }
                
            if(!d.empty() || (d.empty() && num[i] != '0'))
                d.push_back(num[i]);
            i++;
        }
        while(!d.empty() && k > 0){
            k--;
            d.pop_back();
        }
        
        string ans; 
        while(!d.empty()){
            ans.push_back(d.front());
            d.pop_front();
        }
        
        return ans.length() != 0 ? ans : "0";
    }
};