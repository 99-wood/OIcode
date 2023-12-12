#include  <stdio.h>
//函数与x根本就无关，无聊的一道题
int f(int n,int x){
    if(n <= 1) return 1;
    return (n + 1) * n / 2; //等差数列求和
}
int  main()
{
        
        int  n,  x;
        scanf("%d%d",  &n,  &x);
        printf("%d\n",  f(n,  x));
        return  0;
}