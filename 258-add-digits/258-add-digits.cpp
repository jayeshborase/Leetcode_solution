class Solution {
public:
    int addDigits(int num) {
        
        while(num >= 10){
            int i = num%10;
            num /= 10;
            num += i;
        }
        
        return num;
    }
};