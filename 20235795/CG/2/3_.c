#include  <stdio.h>
int  main()
{
        float  score(float  a[],  int  n);
        int  i;
        float  k,  a[10];
        for(i=0;i<10;i++)
                scanf("%f",  &a[i]);
        k=score(a,  10);
        printf("%.2f",  k);
        return  0;
}
float score(float a[], int n){
    float max = -1, min = 1000;
    float sum = 0;
    //找出最值
    for(int i = 0; i < n; ++i){
        if(a[i] > max){
            max = a[i];
        }
        if(a[i] < min){
            min = a[i];
        }
    }
    for(int i = 0; i < n; ++i){
        if(a[i] == max){ //剔除最值，同时防止重复剔除
            max = -1;
            continue;
        }
        if(a[i] == min){
            min = -1;
            continue;
        }
        sum += a[i];
    }
    return sum / (n - 2);
}