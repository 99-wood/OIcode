#include  "stdio.h"
#include  "string.h"
int  main()
{        int  same_set(int  *a,  int  *b,  int  len);
        int  num,  i,  j;
        int  a[100],  b[100];
        scanf("%d",&num);
        for(i=0;i<num;i++)
                scanf("%d",&a[i]);
        for(i=0;i<num;i++)
                scanf("%d",&b[i]);
        printf("%d\n",same_set(a,b,num));
        return  0;
}
/*在下面编写函数int  same_set(int  *a,  int  *b,  int  len)的代码*/
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
int same_set(int *a,  int *b, int len){
    sort(a, len);
    sort(b, len);
    for(int i = 0; i < len; ++i){
        if(a[i] != b[i]) return 0;
    }
    return 1;
}