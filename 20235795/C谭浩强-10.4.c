/*
* File: C-Ì·ºÆÇ¿-10.4.c
* Author: 99_wood
* Date: 2023-10-12
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

//²¹³ä bool ÀàÐÍ 
enum bool {false = 0, true = 1};
#define bool int

#define MAXN 100
#define mid ((l + r) >> 1)

int a[MAXN];
int main(){
	int n, m;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for(int i = n - m; i < n; ++i){
		printf("%d ", a[i]);
	}
	for(int i = 0; i < n - m; ++i){
		printf("%d ", a[i]);
	}
	return 0; 
}
