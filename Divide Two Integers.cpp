class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = llabs(dividend);
        long long b = llabs(divisor);
        long long sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        if(divisor = 0 || (dividend == INT_MIN && divisor == -1)){
            return INT_MAX;
        }
        long long i;
        long long out = 0;
        while(a >= b){
            i = 1;
            while(a >= (b << i)){
                ++i;
            }
            --i;
            out += 1 << i;
            a -= b << i;
        }
        return out*sign;
    }
};
