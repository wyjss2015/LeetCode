int myAtoi(char* str) {
    char *s,flag;
    long long r=0;
    s=str;
    while(*s==' ' && *s!='\0')s++;
    if((*s=='\0'||*s>'9'||*s<'0')&&(*s!='+'&&*s!='-'))return 0;
    else if(*s=='+'||*s=='-')s++;
    else ;
    flag = s-str;
    while(*s!='\0'&&*s<='9'&&*s>='0'){
        r = r * 10 + (*s-'0');
        if(r>INT_MAX&&str[flag-1]=='-')return INT_MIN;
        else if(r>INT_MAX&&str[flag-1]=='+'||r>INT_MAX&&flag-1<0||r>INT_MAX&&str[flag-1]==' ')return INT_MAX;
        s++;
    }
    if(str[flag-1]=='-')return -r;
    return r;
}
