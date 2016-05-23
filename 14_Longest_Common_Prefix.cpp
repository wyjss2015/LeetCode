class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        vector<string>::size_type n;
        n = strs.size();
        string lcpString = "";
        string ::size_type j;
        int flag;
        char c;
        if(n==0)
            lcpString = "";
        else if(n==1)
            lcpString = strs[0];
        else{
            j=0;
            while(true){
                flag = 0;
                for(decltype(strs.size()) i=0;i<strs.size();++i){
                    if(j<strs[i].size()){
                        if(i==0)
                            c = strs[i][j];
                        else if(c==strs[i][j])
                            continue;
                        else{
                            flag = 1;
                            break;
                        }
                    }else{
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    lcpString += c;
                    ++j;
                }
                else
                    break;
            }
        }
        return lcpString;
    }
};
