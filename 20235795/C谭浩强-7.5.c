/*
* File: C-Ì·ºÆÇ¿-7.5.c
* Author: 99_wood
* Date: 2023-10-10
*/
#include<stdio.h>
#include<math.h>
#define MAXN 110
#define mid ((l + r) >> 1)
int a[MAXN];
int main(){
	int n = 10;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; ++i){
		printf("%d ", a[n - i + 1]);
	}
	return 0; 
}
