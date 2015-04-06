class Solution {
public:
    int search(int A[], int n, int target) {
        int left = 0;
        int right = n - 1;
        int out;
        if(target == A[0]) return 0;
        if(target == A[right]) return right;
        if(target > A[left]){
            while(left < right - 1){
                out = (left + right) / 2;
                if(A[out] < A[left]){
                    right = out;
                }
                else{
                    if(A[out] == target){
                        return out;
                    }
                    else if(A[out] < target){
                        left = out;
                    }
                    else{
                        right =out;
                    }
                }
            }
        }
        else{
            while(left < right - 1){
                out = (left + right) / 2;
                if(A[out] > A[right]){
                    left = out;
                }
                else{
                    if(A[out] == target){
                        return out;
                    }
                    else if(A[out] < target){
                        left = out;
                    }
                    else{
                        right = out;
                    }
                }
            }
        }
        return -1;
    }
};
