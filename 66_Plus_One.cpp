class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>::size_type idx, cnt, i;
        for(idx=digits.size(),cnt=0;idx>0&&digits[idx-1]==9;--idx)
            ++cnt;
        if(cnt<digits.size()){
            for(i=1;i<=cnt;++i){
                digits[digits.size()-i] = 0;
            }
            digits[digits.size()-i] += 1;
            return digits;
        }else{
            vector<int> tmp;
            tmp.push_back(1);
            for(i=0;i<digits.size();++i){
                tmp.push_back(0);
            }
            return tmp;
        }
    }
};
