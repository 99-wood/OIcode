
#include <stdio.h>
void swap(int *p1, int *p2);
void exchange(int *a, int *b, int *c);

int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    exchange(&a, &b, &c);
    printf("%d %d %d", a, b, c);
    return 0;
}
void exchange(int *a, int *b, int *c){
 //排序
    int num[3] = {*a, *b, *c};
    for(int i = 0; i < 3; ++i){
        for(int j = 2; j > i; --j){
            if(num[j] < num[j - 1]){
                swap(num + j, num + j - 1);
            }
        }
    }
    *a = num[0];
    *b = num[1];
    *c = num[2];
    return;
}
void swap(int *p1, int *p2){
 //交换
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
    return;
}

