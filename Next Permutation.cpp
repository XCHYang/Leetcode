class Solution {
public:
    void ascend_sort(vector<int> &num, int start, int end){
        if(start >= end) return;
        int num_len = num.size();
        int key = num[start];
        int left = start;
        int right = end;
        while(left < right){
            while(left < right && num[right] >=  key){
                right--;
            }
            if(num[right] < key){
                num[left] = num[right];
                ++left;
            }
            while(left < right && num[left] <= key){
                left++;
            }
            if(num[left] > key){
                num[right] = num[left];
                --right;
            }
        }
        num[left] = key;
        ascend_sort(num, start, left - 1);
        ascend_sort(num, left + 1, end);
        return;
    }
    void nextPermutation(vector<int> &num) {
        int num_len = num.size();
        if(num_len <= 1) return;
        int i;
        for(i = num_len - 1; i > 0; --i){
            if(num[i - 1] < num[i]){
                int max_index = i;
                for(int j = i + 1; j < num_len; j++){
                    if(num[j] < num[max_index] && num[j] > num[i - 1]){
                        max_index = j;
                    }
                }
                int temp = num[max_index];
                num[max_index] = num[i - 1];
                num[i - 1] = temp;
                break;
            }
        }
        ascend_sort(num, i, num_len - 1);
        return;
    }
};
