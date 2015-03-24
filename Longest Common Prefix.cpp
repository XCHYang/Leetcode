class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int min_len;
        int min_index = 0;
        int str_size = strs.size();
        if(str_size == 0) return "";
        min_len = strs[0].length();
        for(int i = 1; i < str_size; i++){
            int temp_len = strs[i].length();
            if(min_len > temp_len){
                min_index = i;
                min_len = temp_len;
            }
        }
        if(min_len == 0) return "";
        string short_str = strs[min_index];
        string com_prefix;
        for(int i = 0; i < min_len; i++){
            for(int j = 0; j < str_size; j++){
                if(short_str[i] - strs[j][i])
                    return com_prefix;
            }
            com_prefix += short_str[i];
        }
        return com_prefix;
    }
};
