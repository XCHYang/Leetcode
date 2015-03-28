class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        map<int, int> num_count;
        vector<vector<int>> out;
        int vec_len = num.size();
        if(vec_len < 3) return out;
        map<int, int>::iterator iter;
        for(int i = 0; i < vec_len; i++){
            iter = num_count.find(num[i]);
            if(iter == num_count.end()){
                num_count.insert(pair<int, int>(num[i], 1));
            }
            else{
                iter->second += 1;
            }
        }
        iter = num_count.find(0);
        if(iter != num_count.end()){
            if(iter->second > 2){
                out.push_back({0, 0, 0});
            }
        }
        map<int, int>::iterator iter_1;
        map<int, int>::iterator iter_2;
        map<int, int>::iterator iter_end;
        iter_end = num_count.end();
        iter_end--;
        int thd_num;
        for(iter = num_count.begin(); iter != iter_end; iter++){
            if(iter->second > 1){
                thd_num = -2 * iter->first;
                if(thd_num > iter->first){
                    iter_1 = num_count.find(thd_num);
                    if(iter_1 != num_count.end()){
                        out.push_back({iter->first, iter->first, thd_num});
                    }
                }
            }
            map<int, int>::iterator iter_temp = iter;
            iter_temp++;
            for(iter_1 = iter_temp; iter_1 != num_count.end(); iter_1++){
                thd_num = -(iter_1->first + iter->first);
                if(thd_num == iter_1->first && iter_1->second > 1){
                    out.push_back({iter->first, thd_num, thd_num});
                }
                if(thd_num > iter_1->first){
                    iter_2 = num_count.find(thd_num);
                    if(iter_2 != num_count.end()){
                        out.push_back({iter->first, iter_1->first, iter_2->first});
                    }
                }
            }
        }
        return out;
    }
};
