class Solution {
public:
    string convert(string s, int nRows) {
        int str_len = s.length();

        string out;
        if(nRows == 1) return s;
        if(str_len <= nRows) return s;
        nRows--;
        for(int i = 0; i < str_len;){
            out += s[i];
            i += 2*nRows;
        }

        for(int i = 1; i < nRows; i++){
            bool flag = 1;
            for(int j = i; j < str_len;){
                if(flag){
                    out += s[j];
                    j += 2*(nRows - i);
                    flag = 0;
                }
                else{
                    out += s[j];
                    j += 2*i;
                    flag = 1;
                }
            }
        }
        for(int i = nRows; i < str_len;){
            out += s[i];
            i += 2*nRows;
        }
        return out;
    }
};
