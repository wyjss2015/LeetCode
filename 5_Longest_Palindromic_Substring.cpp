class Solution {
public:
    string longestPalindrome(string s) {
        string lpSubstring;
        int lpLength=0, tmpLength;
        int i, j, k, r;
        for(i=0;i<s.size();){
            for(j=i;j<s.size()-1&&s[j]==s[j+1];++j)
                ;
            r = j+1;
            for(k=i-1,++j;k>=0&&j<s.size()&&s[k]==s[j];--k,++j)
                ;
            tmpLength = j-k-1;
            if(tmpLength>lpLength){
                lpLength = tmpLength;
                lpSubstring = s.substr(k+1,tmpLength);
            }
            i = r;
        }
        return lpSubstring;
    }
};
