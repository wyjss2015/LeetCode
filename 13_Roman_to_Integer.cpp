class Solution {
public:
    int romanToInt(string s) {
        int sum=0;
        decltype(s.size()) i;
        for(i=1;i<s.size();){
            if(numberMap(s[i-1])>=numberMap(s[i])){
                sum += numberMap(s[i-1]);
                ++i;
            }else{
                sum = sum + numberMap(s[i]) - numberMap(s[i-1]);
                i += 2;
            }
        }
        if(!s.empty() && i-(s.size()-1) == 1)
            sum += numberMap(s[i-1]);
        return sum;
    }
    int numberMap(char c){
        int n;
        switch(c){
            case 'I':
                n = 1;
                break;
            case 'V':
                n = 5;
                break;
            case 'X':
                n = 10;
                break;
            case 'L':
                n = 50;
                break;
            case 'C':
                n = 100;
                break;
            case 'D':
                n = 500;
                break;
            case 'M':
                n = 1000;
                break;
        }
        return n;
    }
};
