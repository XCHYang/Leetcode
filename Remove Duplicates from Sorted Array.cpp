class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(!n) return 0;//n == 0 慢很多
        int i = 0;
        for(int j = 1; j < n; j++){
            if(A[j] - A[j - 1]){
                i++;
                A[i] = A[j];
            }
        }
        i++;
        return i;
    }
};
