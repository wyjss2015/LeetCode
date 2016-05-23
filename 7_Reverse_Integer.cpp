int reverse(int x) {
    int sum,m,max,min;
    long long result=0;
    max = 0x7fffffff;
    min = 0x80000000;
    if(x<0)sum=fabs(x);
    else sum = x;
    while(sum!=0){
        m = sum % 10;
        result = result * 10 + m;
        if(result>max||result<min)return 0;		//溢出处理
        sum = sum / 10;
    }
    if(x<0)result = -result;
    return result;
}
