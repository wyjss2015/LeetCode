class Solution {
public:
    string countAndSay(int n) {
        string preString = "1";
        string nthString;
        int cnt;
        string::size_type s,c;
        for(int i=1;i<n;++i){
            nthString = "";
            cnt = 0;
            for(s=0,c=0;s<preString.size();++s){
                if(preString[c]==preString[s])
                    ++cnt;
                else{
                    nthString += '0'+cnt;
                    nthString += preString[c];
                    cnt = 1;
                    c = s;
                }
            }
            nthString += '0' + cnt;
            nthString += preString[c];
            preString = nthString;
        }
        return preString;
    }
};
