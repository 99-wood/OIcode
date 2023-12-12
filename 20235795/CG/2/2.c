/*
* File: homework.c
* Author: Jiadong Zhang
* Date: 2023-12-1
* 题目：CG平台 top-k问题
*/
#include<stdio.h>
#include<string.h> 
#include<math.h>

#define MAXN 20

int num[MAXN]; //存放输入数据的数组 

void swap(int *a, int *b){ //交换函数 
	int tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}
int main(){
	int n = 10;
	int sum = 0;
	double average = 0;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &num[i]);
	}
	//倒序排序的冒泡排序 
	for(int i = 1; i <= n; ++i){
		for(int j = n; j > i; --j){
			if(num[j] > num[j - 1]){
				swap(&num[j], &num[j - 1]);
			}
		}
	}
	printf("%d\n%d\n%d\n", num[1], num[2], num[3]);
	return 0; 
}
