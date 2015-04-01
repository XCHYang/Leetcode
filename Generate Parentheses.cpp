class Solution {
public:
    void update(vector<string> &temp,string one_case, int m, int n){
        if(m == 0 && n == 0){
            temp.push_back(one_case);
        }
        if(m != 0){
            update(temp, one_case + '(', m - 1, n);
        }
        if(m < n && n != 0){
            update(temp, one_case + ')', m, n - 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> out;
        string one_case = "";
        int left = n;
        int right = n;
        update(out, one_case, left, right);
        return out;
    }
};
