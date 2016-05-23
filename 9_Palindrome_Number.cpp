bool isPalindrome(int x) {
    long long l=1;
    if(x<0)return false;
    while(x/l!=0)l *= 10;		//取得位数
    if(l>=10)l /= 10;
    while(x/l==x%10 && x!=0){		//判断两端数是否相同
        x = (x-x/l*l)/10;		//去两端
        if(l>=100)l /= 100;
    }
    if(x==0)return true;
    else return false;
}
