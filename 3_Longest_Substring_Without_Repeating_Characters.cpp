int lengthOfLongestSubstring(char* s) {
    int count = 0,flag,length = 0;
    char *p,*q,*r;
    p = s;
    while(*p){
        count = 1;
        flag = 1;
        q = p;
        q++;
        while(*q!='\0' && flag != 0){
            for(r=p;r<q;r++){
                if(*r==*q)flag = 0;
            }
            if(flag==1){
                count++;
                q++;
            }
        }
        if(length<count)length = count;
        p++;
    }
    return length;
}
