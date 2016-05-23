class Solution {
public:
    bool isValid(string s) {
        char stack[1000];
        int top=-1;
        for(auto ch:s){
            switch(ch){
                case '(': case '[': case '{':
                    stack[++top] = ch;
                    break;
                case ')':
                    if(top>-1&&stack[top]=='(')
                        --top;
                    else
                        return false;
                    break;
                case ']':
                    if(top>-1&&stack[top]=='[')
                        --top;
                    else
                        return false;
                    break;
                case '}':
                    if(top>-1&&stack[top]=='{')
                        --top;
                    else
                        return false;
                    break;
            }
        }
        if(top!=-1)
            return false;
        else
            return true;
    }
};
