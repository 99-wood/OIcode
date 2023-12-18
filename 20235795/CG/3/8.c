#include  <stdio.h>
int  main()
{
        int    med(int  *a,  int  n);
        int  i,  k,  m;
        int  a[20];
        for(i=0;i<20;i++)
                scanf("%d",  &a[i]);
        scanf("%d",  &k);
        m=med(a,  k);
        printf("%d",  m);
        return  0;
}
void swap(int * a, int * b){ //交换
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}
void sort(int * a, int n){ //排序
    for(int i = 0; i < n; ++i){
        for(int j = n - 1; j > i; --j){
            if(a[j] < a[j - 1]){
                swap(a + j, a + j - 1);
            }
        }
    }
    return;
}
int med(int * a, int n){
    sort(a, n);
    if(n & 1){
        return a[n >> 1];
    }
    else{
        return (a[n >> 1] + a[(n >> 1) - 1]) >> 1;
    }
}