class Solution {
public:
    int strStr(char *haystack, char *needle) {
        if(needle[0] == '\0') return 0;
        int i;
        while(haystack[i] != '\0'){
            if(haystack[i] == needle[0]){
                int j = 1;
                while(needle[j] != '\0'){
                    if(haystack[i + j] == '\0') return -1;
                    if(haystack[i + j] == needle[j]){
                        j++;
                    }
                    else{
                        break;
                    }
                }
                if(needle[j] == '\0') return i;
            }
            i++;
        }
        return -1;
    }
};
