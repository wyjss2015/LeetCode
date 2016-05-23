class Solution {
public:
    int strStr(string haystack, string needle) {
        string::size_type i, j;
        if(haystack.size()<needle.size())
            return -1;
        for(i=0;i<haystack.size()-needle.size()+1;++i){
            for(j=0;j<needle.size();++j){
                if(haystack[i+j]!=needle[j])
                    break;
            }
            if(j==needle.size())
                return i;
        }
        return -1;
    }
};
