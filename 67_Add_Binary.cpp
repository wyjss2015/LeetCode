class Solution {
public:
    string addBinary(string a, string b) {
        string tmp, sum;
        string::size_type size1, size2, n, u, i;
        int c = 0, temp;
        size1 = a.size(); size2 = b.size();
        tmp = (size1>size2) ? a : b;
        n = (size1>size2) ? size2 : size1;
        u = (size1>size2) ? size1 : size2;
        for(i=1;i<=n;++i){
            temp = a[size1-i]-'0' + (b[size2-i]-'0') + c;
            switch(temp){
                case 0:
                    tmp[u-i] = '0';
                    c = 0;
                    break;
                case 1:
                    tmp[u-i] = '1';
                    c = 0;
                    break;
                case 2:
                    tmp[u-i] = '0';
                    c = 1;
                    break;
                case 3:
                    tmp[u-i] = '1';
                    c = 1;
                    break;
            }
        }
        if(c == 0)
            sum = tmp;
        else{
            for(;i<=u&&tmp[u-i]=='1';++i)
                tmp[u-i] = '0';
            if(i<=u){
                tmp[u-i] = '1';
                sum = tmp;
            }else
                sum = '1'+tmp;
        }
        return sum;
    }
};
