/*
* File: homework.c
* Author: Jiadong Zhang
* Date: 2023-12-1
* 题目：CG平台 数之重复次数
*/
#include<stdio.h>
#include<string.h> 
#include<math.h>

#define MAXN 20

int num[MAXN]; // 存放输入数据的数组
int cnt[200010]; // 存放某个数出现次数的桶
 

int main(){
	int n = 10;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &num[i]);
	}
	for(int i = 1; i <= n; ++i){
		++cnt[num[i] + 100000]; // 计数 同时防止负数造成越界 
	}
	int flag = 1; //判断是否输出
	for(int i = 1; i <= 200000; ++i){
		if(cnt[i] == 2){ // 如果当前数满足条件，则输出
			printf("%6d", i - 100000);
			flag = 0; //有输出
		}
	}
	if(flag){
		printf("None");
	}
	return 0; 
}
