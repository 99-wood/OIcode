#include  <stdio.h>
long int fun(int a, int n);
int  main()
{
        int  n,a;
        scanf("%d%d",&a,&n);
        printf("%ld\n",fun(a-1,n-1)+fun(a+1,n+1)+fun(a,n));
        return  0;
}
long int fun(int a, int n){
    long int ans = 0;
    long int now = a;
    // 拆分，按位求和
    do{
        ans += (now * n);
        now *= 10;
    }while(n--);
    return ans;
}