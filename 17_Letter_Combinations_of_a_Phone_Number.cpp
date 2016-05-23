class Solution {
public:
    vector<vector<string>> charts = {{""},{""},
        {"a","b","c"},{"d","e","f"}, {"g","h","i"},{"j","k","l"},{"m","n","o"},{"p","q","r","s"},{"t","u","v"},{"w","x","y","z"}
    };
    vector<string> letterCombinations(string digits) {
        vector<string> ret, subString;
        int idx;
        if(digits == "") return ret;
        idx = digits[0]-'0';
        if(digits.size() == 1){
            for(int i=0;i<charts[idx].size();++i)
                ret.push_back(charts[digits[0]-'0'][i]);
            return ret;
        }
        subString = letterCombinations(digits.substr(1, digits.size()-1));
        for(int i=0;i<charts[idx].size();++i){
            for(int j=0;j<subString.size();++j){
                ret.push_back(charts[idx][i]+subString[j]);
            }
        }
        return ret;
    }
};
