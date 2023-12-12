/*
* File: homework.c
* Author: Jiadong Zhang
* Date: 2023-12-1
* 题目：CG平台 数之查找
*/
#include<stdio.h>
#include<string.h> 
#include<math.h>

#define MAXN 20

int num[MAXN]; //存放输入数据的数组 


int main(){
	int n = 10;
	int sum = 0;
	double average = 0;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &num[i]);
	}
	//求和 
	for(int i = 1; i <= n; ++i){
		sum = sum + num[i];
	}
	//取平均值 
	average = (double)sum / n;
	double delta = 0x3f3f3f3f; //当前结果与平均值的差值 
	int ans;
	for(int i = 1; i <= n; ++i){
		if(num[i] > average && num[i] - average < delta){ //如果当前值比答案更优，则更新答案 
			delta = num[i] - average;
			ans = i;
		}
	}
	printf("%6d%6d", num[ans], ans);
	return 0; 
}
