/*
* File: C-Ì·ºÆÇ¿-10.7.c
* Author: 99_wood
* Date: 2023-10-13
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

//²¹³ä bool ÀàÐÍ 
enum bool {false = 0, true = 1};
#define bool int

#define MAXN 100010
#define mid ((l + r) >> 1)

char str[MAXN];
int main(){
	int n;
	scanf("%d", &n);
	scanf("%s", str);
	int m;
	scanf("%d", &m);
	printf("%s", str + m - 1);
	return 0; 
}
