class Solution {
public:
    string convert(string s, int numRows) {
        string ret;
        int cycle = (numRows-1)*2;
        int p, q;
        int flag;
        int i, j;
        if(numRows==1) return s;
        if(numRows>=2){
            for(j=0;j<s.size();){
                ret += s[j];
                j += cycle;
            }
        }
        if(numRows>2){
            for(i=2;i<=numRows-1;++i){
                flag = 1;
                p = (numRows-i)*2;
                q = cycle - p;
                for(j=i-1;j<s.size();){
                    ret += s[j];
                    if(flag){
                        j += p;
                        flag = 0;
                    }else{
                        j += q;
                        flag = 1;
                    }
                }
            }
        }
        if(numRows>=2){
            for(j=numRows-1;j<s.size();){
                ret += s[j];
                j += cycle;
            }
        }
        return ret;
    }
};
