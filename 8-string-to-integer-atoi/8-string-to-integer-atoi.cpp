class Solution {
public:
    int myAtoi(string s) {
        long int ans = 0, carr = 1;
        int i = 0; 
        while (s[i] == ' ')
            i++;
        
        if(s[i] == '-'){
            carr=-1;
            i++;
        }else if(s[i] == '+'){
            i++;
        }
        while(s[i] >= '0' && s[i] <= '9'){
            ans *= 10;
            ans += s[i]-'0';
            if(ans * carr  >= INT_MAX)
                return INT_MAX;
            else if(ans * carr <= INT_MIN)
                return INT_MIN;
            i++;
        }
        return ans * carr;
    }
};