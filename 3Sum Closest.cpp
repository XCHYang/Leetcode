class Solution {
public:
    void mergeSort(vector<int> &A, size_t low, size_t high){
        if(high - low == 1){
            if(A[low] > A[high]){
                int t = A[high];
                A[high] = A[low];
                A[low] = t;
            }
            return;
        }
        else if(high != low){
            size_t size = high - low + 1;
            size_t median = low + (high - low) / 2;
            mergeSort(A, low, median);
            mergeSort(A, median + 1, high);
            size_t i = 0;
            size_t j = low;
            size_t k = median + 1;
            vector<int> temp;
            while(j <= median && k <= high){
                if(A[j] < A[k]){
                    temp.push_back(A[j]);
                    j++;
                }
                else{
                    temp.push_back(A[k]);
                    k++;
                }
            }
            while(j <= median){
                temp.push_back(A[j]);
                j++;
            }
            while(k <= high){
                temp.push_back(A[k]);
                k++;
            }
            for(i = 0; i < size; i++){
                A[i + low] = temp[i];
            }
        }
        return;
    }
    int threeSumClosest(vector<int> &num, int target) {
        size_t vec_len = num.size();
        mergeSort(num, 0, vec_len - 1);
        size_t max = vec_len - 2;
        int min_diff = INT_MAX;
        int min_sum;
        for(size_t i = 0; i < max; i++){
            size_t j = i + 1;
            size_t k = vec_len - 1;
            int target_1 = target - num[i];
            while(j != k){
                int temp_diff = target_1 - (num[j] + num[k]);
                if(abs(temp_diff)  < abs(min_diff)){
                    min_diff = temp_diff;
                    min_sum = target - temp_diff;
                }
                if(temp_diff == 0) return min_sum;
                if(temp_diff > 0){
                    j++;
                }
                if(temp_diff < 0){
                    k--;
                }
            }
        }
        return min_sum;
    }
};
