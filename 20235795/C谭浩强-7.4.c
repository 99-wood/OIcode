/*
* File: C-Ì·ºÆÇ¿-7.4.c
* Author: 99_wood
* Date: 2023-10-10
*/
#include<stdio.h>
#include<math.h>
#define MAXN 110
#define mid ((l + r) >> 1)
int a[MAXN];
int main(){
	int n = 9;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
	}
	int num, flag = 1;
	scanf("%d", &num);
	for(int i = 1; i <= n; ++i){
		if(a[i] > num && flag){
			printf("%d ", num);
			flag = 0;
		}
		printf("%d ", a[i]);
	}
	return 0; 
}
