#include  <stdio.h>
//统计任一整数中某个位数出现的次数
int Count_Digit(int n, int d){
    if(n < 0) n = -n; //防止负数
    int ans = 0;
    do{
        if((n % 10) == d) ++ans; //逐位判断
        n /= 10;
    }while(n);
    return ans;
}
int  main()
{
        int  N,  D;
        scanf("%d%d", &N, &D);
        printf("%d\n", Count_Digit(N,D));
        return  0;
}
