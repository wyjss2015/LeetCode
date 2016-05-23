class Solution {
public:
    int lengthOfLastWord(string s) {
        string::size_type n, i;
        int cnt=0;
        n = s.size();
        if(n==0)
            return 0;
        while(n>1&&s[n-1]==' ')
            --n;
        if(n==1&&s[0]==' ')
            return 0;
        for(i=n-1;i>0&&s[i]!=' ';--i){
            ++cnt;
        }
        if(i==0&&s[i]!=' ')
            ++cnt;
        return cnt;
    }
};
