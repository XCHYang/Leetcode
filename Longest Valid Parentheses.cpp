class Solution {
public:
    int longestValidParentheses(string s) {
        int s_len = s.length();
        bool* s_valid = new bool[s_len]();
        stack<int> left;
        for(int i = 0; i < s_len; i++){
            switch(s[i]){
                case '(':
                left.push(i);
                break;
                case ')':
                if(!left.empty()){
                    s_valid[left.top()] = true;
                    s_valid[i] = true;
                    left.pop();
                }
                break;
                default:
                break;
            }
        }
        int max_len = 0;
        int temp_len = 0;
        for(int i = 0; i < s_len; i++){
            if(s_valid[i]){
                temp_len++;
            }
            else{
                if(temp_len > max_len){
                    max_len = temp_len;
                }
                temp_len = 0;
            }
        }
        if(temp_len > max_len){
            max_len = temp_len;
        }
        return max_len;
    }
};
