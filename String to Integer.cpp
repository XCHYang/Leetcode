class Solution {
public:
    int atoi(string str) {
        if(str == "") return 0;
        long long sum = 0;
        int str_len = str.length();
        int start_pos = 0;
        int flag = 1;
        for(int i = 0; i < str_len ; i++){
            if(str[i] == ' ')
                continue;
            else{
                start_pos = i;
                break;
            }
        }
        if(str[start_pos] == '+' && str[start_pos + 1] == '-') return 0;
        if(str[start_pos] == '-' && str[start_pos + 1] == '+') return 0;
        if(str[start_pos] == '+') start_pos += 1;
        if(str[start_pos] == '-'){
            start_pos += 1;
            flag = -1;
        }
        long long min = INT_MAX;
        min++;
        for(int i = start_pos; i < str_len; i++){
            int single = str[i] - '0';
            if(single < 0 || single > 9) break;
            sum = sum*10 + single;
            if(sum > INT_MAX && flag == 1){
                return INT_MAX;
            }
            if(sum > min && flag == -1){
                return INT_MIN;
            }
        }
        int x = static_cast<int>(sum);
        return x*flag;
    }
};
