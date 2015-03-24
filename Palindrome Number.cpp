class Solution {
public:
    bool isPalindrome(int x) {
        long long h_base = 1;
        if(x < 0) return false;
        if(x < 10) return true;
        while(x / h_base){
            h_base = h_base * 10;
        }
        h_base = h_base / 10;
        while(h_base >= 10){
            if(x / h_base == x % 10){
                x = x % h_base;
                x = x / 10;
                if(x == 0) return true;
                h_base = h_base / 100;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
