int climbStairs(int n) {
    int C[n+1];
    int i,j,max;
    for(i=0;i<=n;i++){
        C[i] = -1;
    }
    C[0] = 1;
    C[1] = 1;
    C[2] = 2;
    for(i=3;i<=n;i++){
        max = -1;
        for(j=1;j<i;j++){
            if(max<C[j]*C[i-j]+C[j-1]*C[i-j-1])
                max = C[j]*C[i-j]+C[j-1]*C[i-j-1];
        }
        C[i] = max;
    }
    return C[n];
}