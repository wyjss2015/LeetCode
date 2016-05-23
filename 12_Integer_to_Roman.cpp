class Solution {
public:
    string intToRoman(int num) {
        vector<vector<string>> num2str{{"","I","II","III","IV","V","VI","VII","VIII","IX"},
                                    {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
                                    {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
                                    {"","M","MM","MMM"}
                                    };
        string roman;
        roman += num2str[3][num/1000];
        roman += num2str[2][num/100%10];
        roman += num2str[1][num/10%10];
        roman += num2str[0][num%10];
        
        return roman;
    }
};
