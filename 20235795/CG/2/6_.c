#include <stdio.h>


void swap(int *a, int *b){ //交换函数 
	int tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}
int find(int a[],  int n,  int k){
    //冒泡排序
    for(int i = 0; i < n; ++i){
        for(int j = n - 1; j > i; --j){
            if(a[j] > a[j - 1]){
                swap(&a[j], &a[j - 1]);
            }
        }
    }
    return a[k - 1];
}
int main(){
    int  n,  k,  m;
    int  a[20]=  {  10,  18,  99,  20,  50,  36,  80,  206,  989,  66,  88,  75,  166,  156,  306,  605,  258,  369,  586,  866  };
    scanf("%d%d",  &n,  &k);
    m=find(a,  n,  k);
    printf("%d",  m);
    return  0;
}