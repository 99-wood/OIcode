/*
* File: homework.c
* Author: Jiadong Zhang
* Date: 2023-12-12
* 题目：CG平台 学生记录
*/
#include<stdio.h>
#include<string.h> 
#include<math.h>
#include<stdlib.h>

struct student{
    int id, age;
    char name[10];
};

#define MAXN 100

struct student class[MAXN];

void swap(struct student * a, struct student * b){
    struct student tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}
//两种比较函数
int cmp_with_name(struct student a, struct student b){
    return strcmp(a.name, b.name) < 0;
}
int cmp_with_age(struct student a, struct student b){
    return a.age == b.age ? cmp_with_name(a, b) : a.age < b.age;
}
void sort(struct student * a, int len, int (*cmp)(struct student a, struct student b)){ //排序函数
    for(int i = 0; i < len; ++i){
        for(int j = len - 1; j > i; --j){
            if(cmp(class[j], class[j - 1])){
                swap(&class[j], &class[j - 1]);
            }
        }
    }
    return;
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d%s%d", &class[i].id, class[i].name, &class[i].age);
    }
    sort(class, n, &cmp_with_name);
    for(int i = 0; i < n; ++i){
        printf("%3d%6s%3d\n", class[i].id, class[i].name, class[i].age);
    }
    sort(class, n, &cmp_with_age);
    for(int i = 0; i < n; ++i){
        printf("%3d%6s%3d\n", class[i].id, class[i].name, class[i].age);
    }
	return 0;
}

