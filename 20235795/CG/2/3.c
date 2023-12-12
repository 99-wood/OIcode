/*
* File: homework.c
* Author: Jiadong Zhang
* Date: 2023-12-1
* 题目：CG平台 矩阵简单查找
*/
#include<stdio.h>
#include<string.h> 
#include<math.h>

#define MAXN 10

int num[MAXN][MAXN]; //存放输入数据的数组 

void swap(int *a, int *b){ //交换函数 
	int tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}

int main(){
	int n = 5;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			scanf("%d", &num[i][j]);
		}
	}
	//将每行最大的数放到第一个 
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(num[i][j] > num[i][1]){
				swap(&num[i][j], &num[i][1]);
			}
		}
	}
	int ans = 1;
	for(int i = 1; i <= n; ++i){
		if(num[i][1] < num[ans][1]){ //如果当前行的最大值小于当前解，则更新 
			ans = i;
		}
	}
	printf("%d", num[ans][1]);
	return 0; 
}
