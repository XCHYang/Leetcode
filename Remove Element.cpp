class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if(!n) return n;
        int i = 0;
        for(int j = 0; j < n; j++){
            if(A[j] - elem){
                A[i] = A[j];
                i++;
            }
        }
        if(!i && !(A[0] - elem)) return 0;
        return i;
    }
};
