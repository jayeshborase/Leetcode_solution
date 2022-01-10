class Solution {
public:
    string addBinary(string a, string b) {
        int a_si = a.size();
        int b_si = b.size();
        
        string ans;
        char c = '0';
        while(a_si >= 0 && b_si >= 0){
            if(a[a_si] == '1' && b[b_si] == '1'){
                if(c == '1'){
                    ans = '1' + ans;
                    c = '1';
                }else{
                    ans = '0' + ans;
                    c = '1';
                }
            }else if(a[a_si] == '0' && b[b_si] == '1'){
                if(c == '1'){
                    ans = '0' + ans;
                }else{
                    ans = '1' + ans;
                }
            }else if(a[a_si] == '1' && b[b_si] == '0'){
                if(c == '1'){
                    ans = '0' + ans;
                }else{
                    ans = '1' + ans;
                }
            }else if(a[a_si] == '0' && b[b_si] == '0'){
                if(c == '1'){
                    ans = '1' + ans;
                    c = '0';
                }else
                    ans = '0' + ans;
            }
            a_si--;
            b_si--;
        }
        
        while(a_si >= 0){
            if(c == '1' && a[a_si] == '1'){
                ans = '0' + ans;
            }else if(c == '1' || a[a_si] == '1'){
                ans = '1' + ans;
                c = '0';
            }else
                ans = '0' + ans;
            a_si--;
        }
        
        while(b_si >= 0){
            cout << c << " " << b[b_si] << "* ";
            if(c == '1' && b[b_si] == '1'){
                ans = '0' + ans;
            }else if(c == '1' || b[b_si] == '1'){
                ans = '1' + ans;
                c = '0';
            }else
                ans = '0' + ans;
            b_si--;
        }
        
        if(c == '1')
            ans = '1' + ans;
        
        return ans;
    }
};