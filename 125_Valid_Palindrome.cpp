class Solution {
public:
    bool isPalindrome(string s) {
        string::size_type i, j;
        for(i=0,j=s.size();i<j;){
            if(isalnum(s[i]) && isalnum(s[j])){
                if(isupper(s[i])) s[i] = tolower(s[i]);
                if(isupper(s[j])) s[j] = tolower(s[j]);
                if(s[i]!=s[j]) return false;
                ++i;
                --j;
            }else{
                if(!isalnum(s[i])) ++i;
                if(!isalnum(s[j])) --j;
            }
        }
        return true;
    }
};
