class Solution {
public:
    int reverse(int x) {
        long long temp = 0;
        int min = 0x80000000;
        int flag = 1;
        if(x > 0){
            flag = -1;
            x = -x;
        }
        while(x){
            temp = temp * 10 + x % 10;
            if(temp < min) return 0;
            x = x / 10;
        }
        x = static_cast<int>(temp);
        return x*flag;
    }
};
